#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>

//#include <algorithm>
/*
   发布方：发布人的消息
   1.包含头文件
   2.初始化ROS节点
   3.创建节点句柄
   4.创建发布者对象
   5.编写发布逻辑，发布数据

 */



//5.编写发布逻辑，发布数据
void stringCallback(const  std_msgs::String::ConstPtr& msg) {
    //    std::vector<std::string> s;
    std_msgs::String upper;

    std::string original_str = msg->data;
    upper.data = original_str;    //赋值
    ROS_INFO("订阅的消息为 ：%s", upper.data.c_str());   //输出

    std::transform(original_str.begin(), original_str.end(), original_str.begin(), ::toupper);  //转换
    upper.data = original_str;       //赋值
    ROS_INFO("发布的消息为：%s", upper.data.c_str());   //输出
    //发布
    ros::NodeHandle ad_nh;
    ros::Publisher pub = ad_nh.advertise<std_msgs::String>("output_topic", 10);
    pub.publish(upper);
}


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    // ROS_INFO("这是消息的发布方");
 //      2.初始化ROS节点
    ros::init(argc, argv, "string_converter");
    //    3.创建节点句柄
    ros::NodeHandle nh;
    //创建订阅者对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("input_topic", 10, stringCallback);
    //回调函数  
    ros::spin();

    return 0;
}
