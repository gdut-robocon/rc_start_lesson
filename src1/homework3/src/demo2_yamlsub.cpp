#include "ros/ros.h"
#include "std_msgs/String.h"

void doYaml(const std_msgs::String::ConstPtr &yaml)
{
    ROS_INFO("已收到：%s",yaml->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("yaml_param",10,doYaml);
    ros::spin();
    return 0;
}
