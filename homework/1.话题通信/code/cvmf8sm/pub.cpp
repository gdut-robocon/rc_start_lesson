#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>


int main(int argc,char *argv[]){
    ros::init(argc,argv,"erGouZi");
    ros::NodeHandle nh;
    ros::Publisher pub= nh.advertise<std_msgs::String>("input_topic",10);
    std_msgs::String msg;
    ros::Rate rate(10);
    int count=0;
    while(ros::ok()){
        std::string s; std::cin >> s;
        // count++;
        // std::stringstream ss;
        // ss <<"hello-->"<<count;
        // msg.data=ss.str();
        msg.data = s;
        pub.publish(msg);
        ROS_INFO("published data:%s", s.c_str());
        rate.sleep();
    }
    return 0;
}