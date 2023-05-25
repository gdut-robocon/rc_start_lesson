#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p){
    ROS_INFO("参数服务器接收:%s",msg_p->data.c_str());//调试输出
}
int main(int argc, char  *argv[])
{
    /* 
        话题名称：output_topic
        话题内容：收到的被处理过后的大写字母
        消息类型：std_msgs::string
    */
    setlocale(LC_ALL,"");
    //初始化 ROS 节点
    ros::init(argc,argv,"yaml_subscriber");
    //实例化 ROS 句柄
    ros::NodeHandle nh;

    //实例化 订阅者 对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("yaml_param",10,doMsg);
    //处理订阅的消息(回调函数)

    //设置循环调用回调函数
    ros::spin();//循环读取接收的数据，并调用回调函数处理

    return 0;
}