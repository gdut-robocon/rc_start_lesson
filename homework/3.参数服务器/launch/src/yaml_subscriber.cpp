#include "ros/ros.h"
#include "std_msgs/String.h"

void callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("收到的信息为：%s",msg->data.c_str());
}
int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("yaml_param",10,callback);
    ros::spin();
    return 0;
}