#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr &msg){
    std::string original_msg = msg->data;
    std_msgs::String new_msg;
    std::transform(original_msg.begin(),original_msg.end(),original_msg.begin(),::toupper);
    new_msg.data = original_msg;
    ROS_INFO("%s",new_msg.data.c_str());
    ros::NodeHandle nh2;
    ros::Publisher pub = nh2.advertise< std_msgs::String>("output_topic", 1000);
    pub.publish(new_msg);
    
}

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"string_converter");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("original_topic",10,doMsg);
    ros::spin();
    return 0;
}