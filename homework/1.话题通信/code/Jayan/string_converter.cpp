#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
/*
节点名：string_converter

此节点订阅名为“input_topic”的话题
当它收到来自“input_topic”的消息时，它将打印该消息到控制台，并将该消息转换为大写字母字符串。
然后，它将发布这个大写字母字符串到名为“output_topic”的话题上。
*/
static ros::Publisher pub;
void inputCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Received message: %s", msg->data.c_str());//表示收到了小写字符串
  std::string upperCaseString = msg->data;
  std::transform(upperCaseString.begin(), upperCaseString.end(), upperCaseString.begin(), ::toupper);//实现大小写转化
  ROS_INFO("Converted message: %s", upperCaseString.c_str());//打印出转化后的大写字符串
  std_msgs::String output_msg;
  output_msg.data = upperCaseString;
  pub.publish(output_msg);//发布大写字符
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "string_converter");
  ros::NodeHandle nh;
  pub = nh.advertise<std_msgs::String>("output_topic", 1000);//将转换后的字符通过output_topic话题发回去。（第一次把这个函数放在inputCallback里结果发布失败了）
  ros::Subscriber sub = nh.subscribe("input_topic", 1000, inputCallback);//收集发布节点发布的小写字母，丢到inputCallback里面转换字符
  
  ros::spin();
  return 0;
}