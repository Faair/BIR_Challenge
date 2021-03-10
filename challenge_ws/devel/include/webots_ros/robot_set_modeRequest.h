// Generated by gencpp from file webots_ros/robot_set_modeRequest.msg
// DO NOT EDIT!


#ifndef WEBOTS_ROS_MESSAGE_ROBOT_SET_MODEREQUEST_H
#define WEBOTS_ROS_MESSAGE_ROBOT_SET_MODEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace webots_ros
{
template <class ContainerAllocator>
struct robot_set_modeRequest_
{
  typedef robot_set_modeRequest_<ContainerAllocator> Type;

  robot_set_modeRequest_()
    : arg()
    , mode(0)  {
    }
  robot_set_modeRequest_(const ContainerAllocator& _alloc)
    : arg(_alloc)
    , mode(0)  {
  (void)_alloc;
    }



   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _arg_type;
  _arg_type arg;

   typedef int32_t _mode_type;
  _mode_type mode;





  typedef boost::shared_ptr< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> const> ConstPtr;

}; // struct robot_set_modeRequest_

typedef ::webots_ros::robot_set_modeRequest_<std::allocator<void> > robot_set_modeRequest;

typedef boost::shared_ptr< ::webots_ros::robot_set_modeRequest > robot_set_modeRequestPtr;
typedef boost::shared_ptr< ::webots_ros::robot_set_modeRequest const> robot_set_modeRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::webots_ros::robot_set_modeRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::webots_ros::robot_set_modeRequest_<ContainerAllocator1> & lhs, const ::webots_ros::robot_set_modeRequest_<ContainerAllocator2> & rhs)
{
  return lhs.arg == rhs.arg &&
    lhs.mode == rhs.mode;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::webots_ros::robot_set_modeRequest_<ContainerAllocator1> & lhs, const ::webots_ros::robot_set_modeRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace webots_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "352bd896b9891f9831590c1a8d916605";
  }

  static const char* value(const ::webots_ros::robot_set_modeRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x352bd896b9891f98ULL;
  static const uint64_t static_value2 = 0x31590c1a8d916605ULL;
};

template<class ContainerAllocator>
struct DataType< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "webots_ros/robot_set_modeRequest";
  }

  static const char* value(const ::webots_ros::robot_set_modeRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "char[] arg\n"
"int32 mode\n"
;
  }

  static const char* value(const ::webots_ros::robot_set_modeRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.arg);
      stream.next(m.mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct robot_set_modeRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::webots_ros::robot_set_modeRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::webots_ros::robot_set_modeRequest_<ContainerAllocator>& v)
  {
    s << indent << "arg[]" << std::endl;
    for (size_t i = 0; i < v.arg.size(); ++i)
    {
      s << indent << "  arg[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.arg[i]);
    }
    s << indent << "mode: ";
    Printer<int32_t>::stream(s, indent + "  ", v.mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WEBOTS_ROS_MESSAGE_ROBOT_SET_MODEREQUEST_H
