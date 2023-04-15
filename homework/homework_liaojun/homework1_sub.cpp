#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
void callback(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("收到的数据是：%s",msg->data.c_str());
}

int main(int argc, char *argv[])
{ 
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"output_topic");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("string_converter",10,callback);
    ros::spin();
    return 0;
}
