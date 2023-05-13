#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ctype.h"
#include "algorithm"


//ros::NodeHandle nh;//创造句柄发布者订阅者对象
static ros::Subscriber sub;
static ros::Publisher pub;

void deal(const std_msgs::String::ConstPtr& msg_p) {
    std::string msg = msg_p->data.c_str();//创造字符串
    std::transform(msg.begin(), msg.end(), msg.begin(), toupper);//转换大写
    std_msgs::String finalmsg;//创造消息
    finalmsg.data = msg;//赋值
    pub.publish(finalmsg);//发布



}

int main(int argc, char* argv[]) {

    ros::init(argc, argv, "str_converter");
    ros::NodeHandle nh;//创造句柄发布者订阅者对象
    pub = nh.advertise<std_msgs::String>("out_put", 10);//实例化
    sub = nh.subscribe<std_msgs::String>("inpu", 10, deal);
    ros::spin();
    return 0;
}