#include <ros/ros.h>
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("接受到的数据是%s",msg->data.c_str());
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_subscriber");
    ros::NodeHandle nh;
    nh.setParam("my_param","hello!");
    std_msgs::String my_param;
    ros::Subscriber yaml_subscriber = nh.subscribe<std_msgs::String>("my_param", 10, doMsg);
    ros::spin();
    return 0;
}
