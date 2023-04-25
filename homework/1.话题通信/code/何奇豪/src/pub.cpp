#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>



int main(int argc, char *argv[])
{
    /* 
        用来发布input信息
    */

    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"input_topic");
    //创建节点
    ros::NodeHandle string_convert;
    //创建发布者对象
    ros::Publisher pub = string_convert.advertise<std_msgs::String>("input_topic",10);//不超过10条缓存
    //创建被发布的消息
    std_msgs::String messages;
    //10Hz
    ros::Rate rate(1);
    int cnt = 0;
    //填入发布内容
    messages.data = "hello world";
 

    while(ros::ok()){
        pub.publish(messages);
        //调试
        ROS_INFO("发布的数据是：%s",messages.data.c_str());
        rate.sleep();
        ros::Duration(3).sleep();
        cnt++;
        ros::spinOnce();
    }

    return 0;
}