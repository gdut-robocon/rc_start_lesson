#include <ros/ros.h> 
#include <std_msgs/String.h> 
#include <algorithm> 
#include <cctype> 

void inputCallback(const std_msgs::String::ConstPtr& msg) 
{ 
    std::string input_string = msg->data; 
    std::transform(input_string.begin(), input_string.end(), input_string.begin(), [](unsigned char c){ return std::toupper(c); }); 
    ROS_INFO("Received: %s, Converted: %s", msg->data.c_str(), input_string.c_str());
}

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "input_topic"); 
    ros::NodeHandle nh; 
    ros::Subscriber input_sub = nh.subscribe("string_converter", 1000, inputCallback);
}