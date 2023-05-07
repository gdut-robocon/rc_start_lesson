#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>

// 定义一个回调函数，接收订阅的消息，并将其打印到终端上
void callback(const std_msgs::String::ConstPtr& msg)
{
  std::cout << "I received: " << msg->data << std::endl;
}

int main(int argc, char **argv)
{
  // 初始化节点
  ros::init(argc, argv, "yaml_subscriber");
  // 创建节点句柄
  ros::NodeHandle nh;
  // 创建一个订阅者对象，订阅“yaml_param”话题，消息类型为std_msgs::String，队列长度为10，回调函数为callback
  ros::Subscriber sub = nh.subscribe("yaml_param", 10, callback);
  // 循环等待回调函数的执行
  ros::spin();
  return 0;
}