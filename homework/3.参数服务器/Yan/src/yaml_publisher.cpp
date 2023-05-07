#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

int main(int argc, char **argv)
{
  // 初始化节点
  ros::init(argc, argv, "yaml_publisher");
  // 创建节点句柄
  ros::NodeHandle nh;
  // 创建一个发布者对象，发布到“yaml_param”话题，消息类型为std_msgs::String，队列长度为10
  ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param", 10);
  // 创建一个字符串类型的消息对象
  std_msgs::String msg;
  // 创建一个字符串变量，用于存储参数值
  std::string param;
  // 从参数服务器中获取名为“my_param”的参数值，如果没有获取到，则使用默认值
  nh.param<std::string>("my_param", param, "No parameter found.");
  // 将参数值赋给消息对象的data字段
  msg.data = param;
  // 设置发布频率为10Hz
  ros::Rate rate(10);
  // 循环发布消息
  while (ros::ok())
  {
    // 发布消息
    pub.publish(msg);
    // 处理回调函数
    ros::spinOnce();
    // 按照设定的频率休眠
    rate.sleep();
  }
  return 0;
}