#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"
void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("%s",msg->data.c_str());
}
int main(int argc, char *argv[])
{ 
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"output");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("output_topic",1000,doMsg);
    ros::spin();
    return 0;
}