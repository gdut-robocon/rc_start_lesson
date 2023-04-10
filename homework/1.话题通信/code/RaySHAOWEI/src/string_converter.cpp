#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

//设置全局变量 实例化发布者
static ros::Publisher pub;
static ros::Subscriber sub;

void toProcess(const std_msgs::String::ConstPtr& msg_p){
    std::string msg = msg_p->data;//标准库字符串
    std_msgs::String upper_msg;//消息字符串

    std::transform(msg.begin(),msg.end(),msg.begin(),::toupper);//转换

    upper_msg.data = msg;//赋值

    pub.publish(upper_msg);//发布
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");//中文转译

    ros::init(argc,argv,"string_converter");//初始化节点

    ros::NodeHandle string_convert;//ros句柄

    sub = string_convert.subscribe("input_topic",10,toProcess);//订阅

    pub = string_convert.advertise<std_msgs::String>("output_topic",10);//发布

    ros::spin();//回调函数

    return 0;
}