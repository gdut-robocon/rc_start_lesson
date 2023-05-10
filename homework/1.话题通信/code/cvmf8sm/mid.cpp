#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <cctype>

ros::Publisher pub;

void publish(const std_msgs::String::ConstPtr &msg) {
    std::string s = msg->data;
    for(auto &c : s) { c = toupper(c); }
    ROS_INFO("received and sent: %s", s.c_str());
    std_msgs::String m; m.data = s;
    pub.publish(m);
}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "string_converter"); // initialize a ROS node
    ros::NodeHandle nh;
    pub = nh.advertise<std_msgs::String>("output_topic", 10);
    ros::Subscriber sub = nh.subscribe("input_topic", 10, publish);
    ros::spin();
    return 0;
}