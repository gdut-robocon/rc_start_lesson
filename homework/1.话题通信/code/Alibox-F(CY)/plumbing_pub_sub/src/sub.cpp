/*
    需求: 实现基本的话题通信，一方发布数据，一方接收数据，
         实现的关键点:
         1.发送方
         2.接收方
         3.数据(此处为普通文本)


    消息订阅方:
        订阅话题并打印接收到的消息

    实现流程:
        1.包含头文件 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 订阅者 对象
        5.处理订阅的消息(回调函数)
        6.设置循环调用回调函数

*/
// 1.包含头文件 
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"

 static ros::Publisher pub_2;

void doMsg(const std_msgs::String::ConstPtr& msg_p){
    std_msgs::String Caps_msg;
    std::string original_str = msg_p->data;
    std::transform(original_str.begin(), original_str.end(), original_str.begin(), ::toupper);
    Caps_msg.data = original_str;
    ros::NodeHandle ad_nh;
    pub_2 = ad_nh.advertise<std_msgs::String>("output_topic", 10);
    pub_2.publish(Caps_msg);
    ros::Rate r(10);
    r.sleep ();
     std::cout<<"what"<<msg_p->data<<std::endl;
      std::cout<<"what2"<<Caps_msg.data<<std::endl;

    ROS_INFO("我听见:%s",Caps_msg.data.c_str());
    // ROS_INFO("我听见:%s",(*msg_p).data.c_str());
}
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"listener");
    //3.实例化 ROS 句柄
    ros::NodeHandle nh;

    //4.实例化 订阅者 对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("input_topic",10,doMsg);
    //5.处理订阅的消息(回调函数)

    //     6.设置循环调用回调函数
    ros::spin();//循环读取接收的数据，并调用回调函数处理

    return 0;
}
