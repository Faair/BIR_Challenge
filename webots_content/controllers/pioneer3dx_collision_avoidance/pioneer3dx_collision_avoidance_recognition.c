/*
 * Copyright 1996-2020 Cyberbotics Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Description:  A controller moving the Pioneer 3-DX and avoiding obstacles.
                 3 LEDs are switched on and off periodically
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <webots/distance_sensor.h>
#include <webots/led.h>
#include <webots/motor.h>
#include <webots/robot.h>
#include <webots/keyboard.h>
#include <webots/camera.h>
#include <webots/camera_recognition_object.h>

// maximal speed allowed
#define MAX_SPEED 12.3

// how many sensors are on the robot
#define MAX_SENSOR_NUMBER 16

// delay used for the blinking leds
#define DELAY 70

// maximal value returned by the sensors
#define MAX_SENSOR_VALUE 1024

// minimal distance, in meters, for an obstacle to be considered
#define MIN_DISTANCE 0.7

// minimal weight for the robot to turn
#define WHEEL_WEIGHT_THRESHOLD 100

#define TIME_STEP 64

// structure to store the data associated to one sensor
typedef struct {
  WbDeviceTag device_tag;
  double wheel_weight[2];
} SensorData;


// enum to represent the state of the robot
typedef enum { FORWARD, LEFT, RIGHT } State;

// how much each sensor affects the direction of the robot
static SensorData sensors[MAX_SENSOR_NUMBER] = {
  {.wheel_weight = {150, 0}}, {.wheel_weight = {200, 0}}, {.wheel_weight = {300, 0}}, {.wheel_weight = {600, 0}},
  {.wheel_weight = {0, 600}}, {.wheel_weight = {0, 300}}, {.wheel_weight = {0, 200}}, {.wheel_weight = {0, 150}},
  {.wheel_weight = {0, 0}},   {.wheel_weight = {0, 0}},   {.wheel_weight = {0, 0}},   {.wheel_weight = {0, 0}},
  {.wheel_weight = {0, 0}},   {.wheel_weight = {0, 0}},   {.wheel_weight = {0, 0}},   {.wheel_weight = {0, 0}}};

int main() {
  // necessary to initialize Webots
  wb_robot_init();
  double linear = 0.0;
  // stores simulation time step
  int time_step = wb_robot_get_basic_time_step();

  // stores device IDs for the wheels
  WbDeviceTag left_wheel = wb_robot_get_device("left wheel");
  WbDeviceTag right_wheel = wb_robot_get_device("right wheel");
  WbDeviceTag lr = wb_robot_get_device("linear");
  WbDeviceTag cam = wb_robot_get_device("CAM");
  
  wb_camera_enable(cam, TIME_STEP);
  wb_camera_recognition_enable(cam, TIME_STEP);
  
  // stores device IDs for the LEDs
  WbDeviceTag red_led[3];
  red_led[0] = wb_robot_get_device("red led 1");
  red_led[1] = wb_robot_get_device("red led 2");
  red_led[2] = wb_robot_get_device("red led 3");

  char sensor_name[5] = "";
  int i;

  // sets up sensors and stores some info about them
  for (i = 0; i < MAX_SENSOR_NUMBER; ++i) {
    sprintf(sensor_name, "so%d", i);
    sensors[i].device_tag = wb_robot_get_device(sensor_name);
    wb_distance_sensor_enable(sensors[i].device_tag, time_step);
  }

  // sets up wheels
  wb_motor_set_position(left_wheel, INFINITY);
  wb_motor_set_position(right_wheel, INFINITY);
  wb_motor_set_velocity(left_wheel, 0.0);
  wb_motor_set_velocity(right_wheel, 0.0);

  int j, led_number = 0, delay = 0;
  double speed[2] = {0.0, 0.0};
  double wheel_weight_total[2] = {0.0, 0.0};
  double distance, speed_modifier, sensor_value;
  
  while (wb_robot_step(time_step) != -1) {
  
    int number_of_objects = wb_camera_recognition_get_number_of_objects(cam);
    printf("\nRecognized %d objects.\n", number_of_objects);
    
    const WbCameraRecognitionObject *objects = wb_camera_recognition_get_objects(cam);
    
    for (i = 0; i < number_of_objects; ++i) {
      printf("Model of object %d: %s\n", i, objects[i].model);
      printf("Id of object %d: %d\n", i, objects[i].id);
      printf("Relative position of object %d: %lf %lf %lf\n", i, objects[i].position[0], objects[i].position[1],
             objects[i].position[2]);
      printf("Relative orientation of object %d: %lf %lf %lf %lf\n", i, objects[i].orientation[0], objects[i].orientation[1],
             objects[i].orientation[2], objects[i].orientation[3]);
      printf("Size of object %d: %lf %lf\n", i, objects[i].size[0], objects[i].size[1]);
      printf("Position of the object %d on the camera image: %d %d\n", i, objects[i].position_on_image[0],
             objects[i].position_on_image[1]);
      printf("Size of the object %d on the camera image: %d %d\n", i, objects[i].size_on_image[0], objects[i].size_on_image[1]);
      for (j = 0; j < objects[i].number_of_colors; ++j)
        printf("- Color %d/%d: %lf %lf %lf\n", j + 1, objects[i].number_of_colors, objects[i].colors[3 * j],
               objects[i].colors[3 * j + 1], objects[i].colors[3 * j + 2]);
    }
    
  int key = wb_keyboard_get_key();
  wb_keyboard_enable(TIME_STEP);
  
  if(key == WB_KEYBOARD_UP){
    linear += 0.005;
  } else if(key == WB_KEYBOARD_DOWN){
      linear += -0.005;
      }
  else{
    linear += 0;
    }
  wb_motor_set_position(lr, linear);    
   }
  
  // by default, the robot goes forward
  /*State state = FORWARD;

  // run simulation
  while (wb_robot_step(time_step) != -1) {
    // initialize speed and wheel_weight_total arrays at the beginning of the loop
    memset(speed, 0, sizeof(double) * 2);
    memset(wheel_weight_total, 0, sizeof(double) * 2);

    for (i = 0; i < MAX_SENSOR_NUMBER; ++i) {
      sensor_value = wb_distance_sensor_get_value(sensors[i].device_tag);

      // if the sensor doesn't see anything, we don't use it for this round
      if (sensor_value == 0.0)
        speed_modifier = 0.0;
      else {
        // computes the actual distance to the obstacle, given the value returned by the sensor
        distance = 5.0 * (1.0 - (sensor_value / MAX_SENSOR_VALUE));  // lookup table inverse.

        // if the obstacle is close enough, we may want to turn
        // here we compute how much this sensor will influence the direction of the robot
        if (distance < MIN_DISTANCE)
          speed_modifier = 1 - (distance / MIN_DISTANCE);
        else
          speed_modifier = 0.0;
      }

      // add the modifier for both wheels
      for (j = 0; j < 2; ++j)
        wheel_weight_total[j] += sensors[i].wheel_weight[j] * speed_modifier;
    }

    // (very) simplistic state machine to handle the direction of the robot
    switch (state) {
      // when the robot is going forward, it will start turning in either direction when an obstacle is close enough
      case FORWARD:
        if (wheel_weight_total[0] > WHEEL_WEIGHT_THRESHOLD) {
          speed[0] = 0.3 * MAX_SPEED;
          speed[1] = -0.3 * MAX_SPEED;
          state = LEFT;
        } else if (wheel_weight_total[1] > WHEEL_WEIGHT_THRESHOLD) {
          speed[0] = -0.3 * MAX_SPEED;
          speed[1] = 0.3 * MAX_SPEED;
          state = RIGHT;
        } else {
          speed[0] = MAX_SPEED;
          speed[1] = MAX_SPEED;
        }
        break;
      // when the robot has started turning, it will go on in the same direction until no more obstacle are in sight
      // this will prevent the robot from being caught in a loop going left, then right, then left, and so on.
      case LEFT:
        if (wheel_weight_total[0] > WHEEL_WEIGHT_THRESHOLD || wheel_weight_total[1] > WHEEL_WEIGHT_THRESHOLD) {
          speed[0] = 0.3 * MAX_SPEED;
          speed[1] = -0.3 * MAX_SPEED;
        } else {
          speed[0] = MAX_SPEED;
          speed[1] = MAX_SPEED;
          state = FORWARD;
        }
        break;
      case RIGHT:
        if (wheel_weight_total[0] > WHEEL_WEIGHT_THRESHOLD || wheel_weight_total[1] > WHEEL_WEIGHT_THRESHOLD) {
          speed[0] = -0.3 * MAX_SPEED;
          speed[1] = 0.3 * MAX_SPEED;
        } else {
          speed[0] = MAX_SPEED;
          speed[1] = MAX_SPEED;
          state = FORWARD;
        }
        break;
    }

    // the three red LEDs are swicthed on and off periodically
    ++delay;
    if (delay == DELAY) {
      wb_led_set(red_led[led_number], 0);
      ++led_number;
      led_number = led_number % 3;
      wb_led_set(red_led[led_number], 1);
      delay = 0;
    }
    // sets the motor speeds
    wb_motor_set_velocity(left_wheel, speed[0]);
    wb_motor_set_velocity(right_wheel, speed[1]);
  }

  wb_robot_cleanup();
*/
  return 0;
}
