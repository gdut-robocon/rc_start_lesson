#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"


int main(int argc, char *argv[])
{
    //处理乱码问题
    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"pub");
    //实例化句柄
    ros::NodeHandle nh;
    //实例化发布者对象
    ros::Publisher pub=nh.advertise<std_msgs::String>("input_topic",10);
    std_msgs::String msg;
    
    //节点不死
    while (ros::ok())
    {
        std::string ans;
        //输入待发布的消息
        getline(std::cin,ans);
        msg.data=ans;
        //发布消息
        pub.publish(msg);
        ROS_INFO("发布的数据：%s",msg.data.c_str());
        ros::spinOnce();
    }
    return 0;
}