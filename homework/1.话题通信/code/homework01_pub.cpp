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


int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"pub_c");
    setlocale(LC_ALL,"");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic",10);
    std_msgs::String msg;
    msg.data = "hello world";
    ros::Rate r(1);

    while (ros::ok())
    {
        pub.publish(msg);
        ROS_INFO("打印的消息是：%s",msg.data.c_str());
        r.sleep();
       ros::spinOnce();
        
    }
    
    return 0;
}
