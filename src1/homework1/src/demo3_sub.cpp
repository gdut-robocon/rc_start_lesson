#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string.h"

void doMsg(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("已收到消息，收到的消息为：%s",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("ouput_topic",10,doMsg);
    ros::spin();
    return 0;
}
