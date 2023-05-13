#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string.h"

/*
订阅的话题名称为“input_topic”，消息类型为std_msgs::String。
发布的话题名称为“output_topic”，消息类型为std_msgs::String。
节点名称应为“string_converter”。
*/

void doMsg(const std_msgs::String::ConstPtr &msg)
{
    //实例化ros句柄
    static ros::NodeHandle nh_big;
    //实例化话题对象
    ros::Publisher pub_big = nh_big.advertise<std_msgs::String>("ouput_topic",100);
    //设置发布信息
    std_msgs::String big_msg;
    std::string small_msg = msg->data;
    std::transform(small_msg.begin(), small_msg.end(), small_msg.begin(), ::toupper);
    big_msg.data = small_msg;
    //发布信息
    //ROS_INFO("已收到消息，收到的消息为：%s",big_msg.data.c_str());
    pub_big.publish(big_msg);
    
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"string_converter");
    //实例化ros句柄
    ros::NodeHandle nh_small;
    //实例化话题对象
    ros::Subscriber sub_small = nh_small.subscribe("input_topic",100,doMsg);
    ros::spin();
    return 0;
}
