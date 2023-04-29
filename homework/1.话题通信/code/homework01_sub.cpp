#include "ros/ros.h"
#include "std_msgs/String.h"
/*

    编写一个ROS节点，该节点订阅名为“input_topic”的字符串类型话题，并将其转换为大写字母，并通过名
    为“output_topic”的新话题发布结果。例如，如果输入是“hello world”，那么输出应该是“HELLO WORLD”。
    要求：
        订阅的话题名称为“input_topic”，消息类型为std_msgs::String。
        发布的话题名称为“output_topic”，消息类型为std_msgs::String。
        节点名称应为“string_converter”。
        使用C++编写节点。


*/
ros::Publisher pub;
void domsg(const std_msgs::String::ConstPtr& msg_p)
{
    std::string msg = msg_p->data;
    std_msgs::String up_msgs;
    ROS_INFO("订阅的数据是：%s",msg_p->data.c_str());
    //转换大小写
    std::transform(msg.begin(),msg.end(),msg.begin(),::toupper);
    up_msgs.data = msg;
    pub.publish(up_msgs);
    ROS_INFO("发布的数据是：%s",up_msgs.data.c_str());


}
int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"sub_c");
    setlocale(LC_ALL,"");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("input_topic",10,domsg);
    pub = nh.advertise<std_msgs::String>("out_topic",10);
    ros::spin();


    return 0;
}
