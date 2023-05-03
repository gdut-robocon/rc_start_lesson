#include "ros/ros.h"
#include "string"
#include "std_msgs/String.h"

/*
   发布方：发布人的消息
   1.包含头文件
   2.初始化ROS节点
   3.创建节点句柄
   4.创建发布者对象
   5.编写发布逻辑，发布数据


 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    ROS_INFO("这是消息的发布方");
    //      2.初始化ROS节点
    ros::init(argc, argv, "Pub");
    //    3.创建节点句柄
    ros::NodeHandle nh;
    //    4.创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic", 10);  //功能包和msgs名
    //    5.编写发布逻辑，发布数据
       //5.1 创建被发布的数据
    std_msgs::String topic;
    topic.data = "hello world";
    //5-2 设置发布频率
    ros::Rate rate(1);

    //5-3 循环发布数据
    while (ros::ok)
    {
        //核心：数据发布
        pub.publish(topic);
        ROS_INFO("发布的消息: %s", topic.data.c_str());
        //休眠
        rate.sleep();

    }


    return 0;
}

