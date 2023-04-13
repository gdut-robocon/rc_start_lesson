#include <ros/ros.h>
#include <std_msgs/String.h>

/*
读取并发布小写字符串
订阅并打印大写字符串
*/
void outputCallback(const std_msgs::String::ConstPtr& msg_p)
{
  ROS_INFO("I heard: [%s]", msg_p->data.c_str());//打印出最后接收到的大写
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "string_converter_test");
  ros::NodeHandle n;
  ros::Publisher input_pub = n.advertise<std_msgs::String>("input_topic", 1000);//建立发布函数将输入的小写字符串发布
  ros::Subscriber output_sub = n.subscribe<std_msgs::String>("output_topic", 1000, outputCallback);//订阅回转换成大写的字符串
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    std_msgs::String msg;
    std::getline(std::cin, msg.data);//读取输入字符
    input_pub.publish(msg);//发布
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}


