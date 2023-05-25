#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>

int main(int argc, char *argv[])
{
    /* 
        话题名称：input_topic
        话题内容：小写字母
        消息类型：std_msgs::string
    */

    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"publisher");
    //创建节点
    ros::NodeHandle nh;
    //创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic",10);//不超过10条缓存
    //创建被发布的消息
    std_msgs::String messages;
    //10Hz
    ros::Rate rate(1);
    //填入发布内容
    messages.data = "hello world";
 
    ros::Duration(3).sleep();
    while(ros::ok()){
        //发布数据
        pub.publish(messages);
        //调试
        ROS_INFO("发布端：%s",messages.data.c_str());

        rate.sleep();
        
        ros::spinOnce();
    }

    return 0;
}