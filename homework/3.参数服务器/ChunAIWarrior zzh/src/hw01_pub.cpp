#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"


int main(int argc, char *argv[])
{
    //处理乱码问题
    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"yaml_publisher");
    //实例化句柄
    ros::NodeHandle nh;
    //实例化发布者对象
    ros::Publisher pub=nh.advertise<std_msgs::String>("yaml_param",10);
    std_msgs::String msg;
    bool flag=nh.getParam("my_param",msg.data);
    ros::Rate rate(1);
    
    //节点不死
    while (ros::ok())
    {
        //发布消息
        pub.publish(msg);
        if(flag)
        ROS_INFO("发布的数据：%s",msg.data.c_str());
        else
        ROS_INFO("找不到对象 O_o");
        
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}