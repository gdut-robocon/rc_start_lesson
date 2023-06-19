#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "yaml_publister");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param", 10);
    std_msgs::String word;
    std::string myyaml="wu";
    ros::param::get("my_param", myyaml);
    ros::Rate rate(10);
    while (ros::ok) 
    {
        word.data = myyaml;  
        ROS_INFO("发布的消息为：%s", word.data.c_str());
        pub.publish(word);
        rate.sleep();
    }
    return 0;
}