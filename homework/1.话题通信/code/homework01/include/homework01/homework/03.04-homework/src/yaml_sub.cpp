#include "ros/ros.h"
#include "std_msgs/String.h"

void home(const std_msgs::String::ConstPtr& puppet)
{
    ROS_INFO("对方给你发送的消息是：%s",puppet->data.c_str());
}

int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_subscriber");
    ros::NodeHandle you;

    ros::Subscriber zwt = you.subscribe("yaml_param",10,home);

    ros::spin();
    return 0;
}