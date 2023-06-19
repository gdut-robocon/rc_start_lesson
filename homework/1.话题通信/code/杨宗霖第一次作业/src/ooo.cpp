#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

void Callback(const std_msgs::String::ConstPtr& msg) {
    ros::NodeHandle ad_nh;
    ros::Publisher pub = ad_nh.advertise<std_msgs::String>("output_topic", 1000);
    std_msgs::String big;
    std::string small = msg->data;
    std::transform(small.begin(), small.end(), small.begin(), ::toupper);
    big.data = small;
    pub.publish(big);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "string_converter");
    ros::NodeHandle nh;
    ros::NodeHandle ad_nh;
    ros::Publisher pub = ad_nh.advertise<std_msgs::String>("output_topic", 1000);
    ros::Subscriber sub = nh.subscribe("input_topic", 1000,Callback);
    ros::spin();
    return 0;
}