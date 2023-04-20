#include "ros/ros.h"
#include "std_msgs/String.h"
#include "iostream"
#include "sstream"

using namespace std;
int main(int agrc, char*agrv[])
{   setlocale(LC_ALL,"");
    ros::Rate r(1);
    ros::init(agrc,agrv,"input");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic",1000);
    std_msgs::String msg;
     while(ros::ok())
    {
        std::string str;
        ROS_INFO("输入小写英文");
        std::getline(std::cin,str);
        msg.data=str;
        pub.publish(msg);

    }
    return 0;
}