#include "ros/ros.h"
#include "std_msgs/String.h"
/*
订阅的话题名称为“input_topic”，消息类型为std_msgs::String。
发布的话题名称为“output_topic”，消息类型为std_msgs::String。
节点名称应为“string_converter”。
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"publisher");
    //实例化ros句柄
    ros::NodeHandle nh;
    //实例化话题对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic",100);
    //等待注册完成
    ros::Duration(2).sleep();
    //设置速度
    ros::Rate rate(10);
    //设置发布信息
    std_msgs::String msg;
    msg.data = "hello world";
    //循环发布
    while(ros::ok())
    {
        pub.publish(msg);
        ROS_INFO("发布的信息是：%s",msg.data.c_str());
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}

