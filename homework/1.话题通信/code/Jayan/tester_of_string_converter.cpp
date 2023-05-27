#include <ros/ros.h>
#include <std_msgs/String.h>

/*
节点名：string_converter_test
用于测试与接收string_converter节点
    1: 此节点从控制台读取用户输入的字符串，字符串以回车为结束符。
    2：此节点把读取到的字符串通过名为“input_topic”的话题发布出去。
    3: 此节点订阅名称为“output_topic”的话题。
    4：此节点将收到的订阅名为“output_topic”的字符串输出到控制台。

使用方法：
     运行此节点后在控制台输入小写字符串，abc
     可以从控制台看到stirng_converter节点返回大写的ABC
*/
void outputCallback(const std_msgs::String::ConstPtr& msg_p)
{
  ROS_INFO("I heard: [%s]", msg_p->data.c_str());//打印出最后接收到的大写
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "string_converter_test");
  ros::NodeHandle n;
  ros::Publisher input_pub = n.advertise<std_msgs::String>("input_topic", 1000);//初始化发布函数
  ros::Subscriber output_sub = n.subscribe<std_msgs::String>("output_topic", 1000, outputCallback);//订阅回转换成大写的字符串
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    std_msgs::String msg;
    std::getline(std::cin, msg.data);//读取输入字符
    input_pub.publish(msg);//发布小写的字符串
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}


