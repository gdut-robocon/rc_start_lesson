#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"

void domsg(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("我收到了: %s", msg->data.c_str());
}

int main(int argc, char **argv)
{
  setlocale(LC_ALL,"");
  // 初始化节点
  ros::init(argc, argv, "yaml_subscriber");
  // 创建节点句柄
  ros::NodeHandle nh;
  
  ros::Subscriber sub = nh.subscribe("yaml_param", 10, domsg);
  
  ros::spin();
  return 0;
}
