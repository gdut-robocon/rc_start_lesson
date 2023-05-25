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

    //创建获取参数的变量
    std::string msg = "false";
    
    //创建发布消息的变量
    std_msgs::String messages;

    //获取参数信息
    nh.getParam("my_param",msg);
    
    //填入发布内容
    messages.data = msg;

    //设置发布频率
    ros::Rate rate(2);

    //发布数据
    while (ros::ok())
    {
        pub.publish(messages);
        ("参数服务器发布：%s",messages.data.c_str());
        
        rate.sleep();

        ros::spinOnce(); 
    }
    return 0;
}