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
    ros::init(argc,argv,"yaml_publisher");
    //创建节点
    ros::NodeHandle nh;
    //创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param",10);//不超过10条缓存
    ros::Duration(1).sleep();
    //创建被发布的消息
    std::string msg = "false";
    std_msgs::String messages;
    //填入发布内容
    nh.getParam("my_param",msg);
    messages.data = msg;

    //发布数据
    pub.publish(messages);
    ROS_INFO("参数服务器发布：%s",messages.data.c_str());
    ros::spinOnce();

    return 0;
}