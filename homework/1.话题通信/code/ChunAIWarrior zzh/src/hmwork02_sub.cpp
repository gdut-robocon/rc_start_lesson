#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"
#include <cctype>
#include <algorithm>

static ros::Publisher pub1;
static ros::Subscriber sub;

void doMsg(const std_msgs::String::ConstPtr &msg){
    std::string str=msg->data.c_str();
    //处理接受到的数据（小写转大写）
    transform(str.begin(),str.end(),str.begin(),::toupper);
    //发布处理完的数据
    std_msgs::String refl;
    refl.data=str;
    pub1.publish(refl);
    ROS_INFO("处理后的数据：%s",refl.data.c_str());
}

int main(int argc, char *argv[])
{
    //处理乱码问题
    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"string_converter");
    //实例化句柄
    ros::NodeHandle nh;
    //实例化发布者对象
    sub=nh.subscribe("input_topic",10,doMsg);
    //循环读取接收的数据，并调用回调函数处理
    pub1=nh.advertise<std_msgs::String>("output_topic",10);//发布
    
    ros::spin();
    return 0;
}
