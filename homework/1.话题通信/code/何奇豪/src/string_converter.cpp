#include "ros/ros.h"
#include "std_msgs/String.h"
/*
编写一个ROS节点，该节点订阅名为“input_topic”的字符串类型话题，并将其转换为大写字母，并通过名为“output_topic”的新话题发布结果。例如，如果输入是“hello world”，那么输出应该是“HELLO WORLD”。

要求：

1. 订阅的话题名称为“input_topic”，消息类型为std_msgs::String。
2. 发布的话题名称为“output_topic”，消息类型为std_msgs::String。
3. 节点名称应为“string_converter”。
4. 使用C++编写节点。

*/

//设置全局变量
static ros::Publisher pub;
static ros::Subscriber sub;

void doMsg(const std_msgs::String::ConstPtr& msg_p){
    std::string msg = msg_p->data;
    std_msgs::String upper_msg;
    //打印订阅到的信息
    ROS_INFO("订阅的数据：%s",msg_p->data.c_str());
    //将订阅到的消息转换为大写
    std::transform(msg.begin(),msg.end(),msg.begin(),::toupper);
    upper_msg.data = msg;
    //发布处理后的消息
    pub.publish(upper_msg);
    //打印发布的信息
    ROS_INFO("发布的数据：%s",upper_msg.data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化ROS节点
    ros::init(argc,argv,"string_converter");
    //实例化ROS句柄
    ros::NodeHandle string_converter;
    //订阅消息
    sub = string_converter.subscribe("input_topic",10,doMsg);
    //发布消息
    pub = string_converter.advertise<std_msgs::String>("output_topic",10);
    //回调函数处理消息
    ros::spin();

    return 0;
}