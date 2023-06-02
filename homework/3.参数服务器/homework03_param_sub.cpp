#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"

void doMsg(const  std_msgs::String::ConstPtr& msg) 
{
    ROS_INFO("接收到的消息为：%s", msg->data.c_str());
}
int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "");
    ros::init(argc, argv, "yaml_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("yaml_param", 10, doMsg);
    ros::spin();
    return 0;
}