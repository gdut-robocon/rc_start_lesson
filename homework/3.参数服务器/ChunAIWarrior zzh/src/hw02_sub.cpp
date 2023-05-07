#include "ros/ros.h"
#include "std_msgs/String.h"

static ros::Subscriber sub;
void doMsg(const std_msgs::String::ConstPtr &msg){
    ROS_INFO("接收到的数据：%s",msg->data.c_str());
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_subscriber");
    ros::NodeHandle nh;
    sub=nh.subscribe("yaml_param",10,doMsg);
    ros::spin();
    return 0;
}
