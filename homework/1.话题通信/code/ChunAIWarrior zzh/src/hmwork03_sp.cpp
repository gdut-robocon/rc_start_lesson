#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"

void doMsg1(const std_msgs::String::ConstPtr &refl){
    
    ROS_INFO("新发布数据的数据：%s",refl->data.c_str());
}


int main(int argc, char *argv[])
{
    //处理乱码问题
    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"sub1");
    //实例化句柄
    ros::NodeHandle nh;
    //实例化发布者对象
    ros::Subscriber sub1=nh.subscribe<std_msgs::String>("output_topic",10,doMsg1);
    ros::spin();

    return 0;
}