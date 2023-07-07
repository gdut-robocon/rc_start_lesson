#include "ros/ros.h"
#include "std_msgs/String.h"

//回调函数
void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("炜佳认可了：%s",msg->data.c_str());
    //或者写成：ROS_INFO("炜佳认可了：%s",(*msg).data.c_str());
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化ros结点
    ros::init(argc,argv,"subscriber");
    //实例化ros句柄
    ros::NodeHandle nh;
    //实例化话题对象
    ros::Subscriber sub = nh.subscribe("topic",10,doMsg);
    ros::spin();
    return 0;
}
