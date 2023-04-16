#include "ros/ros.h"
#include "std_msgs/String.h"
void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("%s",msg->data.c_str());
}
int main(int argc,char* argv[])
{
    ros::init(argc,argv,"shuchu");
    ros::NodeHandle nh;
    ros::Subscriber converter = nh.subscribe("output_topic",1000,doMsg);
    ros::spin();
    return 0;
}