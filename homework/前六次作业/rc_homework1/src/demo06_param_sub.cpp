#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p){
    std_msgs::String messgae;
    messgae.data=msg_p->data;
    ROS_INFO("我听见:%s",messgae.data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"yaml_subscriber");
    //3.实例化 ROS 句柄
    ros::NodeHandle nh;

    //4.实例化 订阅者 对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("yaml_param",10,doMsg);

    ros::spin();
    return 0;
}
