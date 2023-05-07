#include <ros/ros.h>
#include "std_msgs/String.h"
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"output_topic");
    ros::NodeHandle nh;
    ros::Publisher pub= nh.advertise< std_msgs::String>("original_topic", 1000);
    std_msgs::String msg;
    ros::Rate rate(10);
    ros::Duration(3).sleep();
    while(ros::ok()){
        msg.data ="hello world";
        pub.publish(msg);
        ROS_INFO("%s",msg.data.c_str());
        rate.sleep();
    }

    return 0;
}
