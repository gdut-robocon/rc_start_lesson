#include "ros/ros.h"
#include "std_msgs/String.h"  //消息类型
#include <iostream>   //C++标准库
#include <algorithm>    //使用C++语法转换大小写 

ros::Publisher pub;  //main函数里面声明的用不到回调函数里，所以可使用全局变量

void Bigword(const std_msgs::String::ConstPtr &msg)  //回调函数，把得到的值引用到msg
{  
    std::string Data = msg->data.c_str();  //需要定义一个字符串变量来接收，使用指针传输
     
    transform(Data.begin(),Data.end(),Data.begin(),::toupper); //转换大小写

    std_msgs::String answer ; //定义一个消息类型用来交互信息

    answer.data = Data; //把计算的值传给消息类型旗下的data
    
    pub.publish(answer);
         
    ROS_INFO("转换的大写为: %s", Data.c_str());
}

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"string_converter");

    ros::NodeHandle h;

    ros::Subscriber sub = h.subscribe("input_topic",10,Bigword);

    pub = h.advertise<std_msgs::String>("output_topic",10);

    ros::Rate rate(5);

    ros::Duration(3).sleep();

    ros::spin();  //spin函数放末尾，执行后会在回调函数中不断循环接收新消息，所以其后面的语句不会被执行

    return 0;
}