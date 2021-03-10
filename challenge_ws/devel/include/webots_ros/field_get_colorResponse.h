// Generated by gencpp from file webots_ros/field_get_colorResponse.msg
// DO NOT EDIT!


#ifndef WEBOTS_ROS_MESSAGE_FIELD_GET_COLORRESPONSE_H
#define WEBOTS_ROS_MESSAGE_FIELD_GET_COLORRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/ColorRGBA.h>

namespace webots_ros
{
template <class ContainerAllocator>
struct field_get_colorResponse_
{
  typedef field_get_colorResponse_<ContainerAllocator> Type;

  field_get_colorResponse_()
    : value()  {
    }
  field_get_colorResponse_(const ContainerAllocator& _alloc)
    : value(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::ColorRGBA_<ContainerAllocator>  _value_type;
  _value_type value;





  typedef boost::shared_ptr< ::webots_ros::field_get_colorResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::webots_ros::field_get_colorResponse_<ContainerAllocator> const> ConstPtr;

}; // struct field_get_colorResponse_

typedef ::webots_ros::field_get_colorResponse_<std::allocator<void> > field_get_colorResponse;

typedef boost::shared_ptr< ::webots_ros::field_get_colorResponse > field_get_colorResponsePtr;
typedef boost::shared_ptr< ::webots_ros::field_get_colorResponse const> field_get_colorResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::webots_ros::field_get_colorResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::webots_ros::field_get_colorResponse_<ContainerAllocator1> & lhs, const ::webots_ros::field_get_colorResponse_<ContainerAllocator2> & rhs)
{
  return lhs.value == rhs.value;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::webots_ros::field_get_colorResponse_<ContainerAllocator1> & lhs, const ::webots_ros::field_get_colorResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace webots_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::field_get_colorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::field_get_colorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::field_get_colorResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3fa1443a84523e49855f24a6bde287af";
  }

  static const char* value(const ::webots_ros::field_get_colorResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3fa1443a84523e49ULL;
  static const uint64_t static_value2 = 0x855f24a6bde287afULL;
};

template<class ContainerAllocator>
struct DataType< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "webots_ros/field_get_colorResponse";
  }

  static const char* value(const ::webots_ros::field_get_colorResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/ColorRGBA value\n"
"\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/ColorRGBA\n"
"float32 r\n"
"float32 g\n"
"float32 b\n"
"float32 a\n"
;
  }

  static const char* value(const ::webots_ros::field_get_colorResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct field_get_colorResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::webots_ros::field_get_colorResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::webots_ros::field_get_colorResponse_<ContainerAllocator>& v)
  {
    s << indent << "value: ";
    s << std::endl;
    Printer< ::std_msgs::ColorRGBA_<ContainerAllocator> >::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_FIELD_GET_COLORRESPONSE_H
