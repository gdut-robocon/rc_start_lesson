#include <ros/ros.h>
#include <std_msgs/String.h>
#include <algorithm> // std::transform
#include <cctype> // std::toupper

//Because I always forgot to switch the input method,
// my code reported errors, so I uninstalled the Chinese input method TT

void stringCallback(const std_msgs::String::ConstPtr& msg)
{
    //the type of msg is"std_msgs::string
    std_msgs::String output_msg;
    output_msg.data = msg->data;

    // exchange it into the toupper
    std::transform(output_msg.data.begin(), output_msg.data.end(), output_msg.data.begin(), [](char c){ return std::toupper(c); });

    // pub the exchanged words
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("output_topic", 1000);
    pub.publish(output_msg);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "string_converter");
    //the name of node is "string_converter"
    
    ros::NodeHandle nh;

    // and subscribe the topic
    ros::Subscriber sub = nh.subscribe("input_topic", 1000, stringCallback);

    ros::spin();

    return 0;
}

