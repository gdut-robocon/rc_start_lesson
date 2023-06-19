#include "ros/ros.h"
#include "std_msgs/String.h"
#include "iostream"
using namespace std;

int main(int agrc, char*agrv[])
{   setlocale(LC_ALL,"");
    ros::init(agrc,agrv,"shuru");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic",1000);
    std_msgs::String msg;
    ros::Rate rate(1);
    while(ros::ok())
    {
        std::string str;
        ROS_INFO("输入的小写英文");
        std::getline(std::cin,str);
        msg.data=str;
        pub.publish(msg);

    }
    return 0;
}