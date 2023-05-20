```cpp
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

void stringCallback(const std_msgs::String::ConstPtr& msg) {
    std_msgs::String upper_msg;
    std::string original_str = msg->data;
    std::transform(original_str.begin(), original_str.end(), original_str.begin(), ::toupper);
    upper_msg.data = original_str;
    ros::NodeHandle ad_nh;
    ros::Publisher pub = ad_nh.advertise<std_msgs::String>("output_topic", 1000);
    pub.publish(upper_msg);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "string_converter");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("input_topic", 1000, stringCallback);
    ros::spin();
    return 0;
}
```
/发布方
include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息
int main(int argc, char  *argv[])
{   
    //设置编码
    setlocale(LC_ALL,"");

    //2.初始化 ROS 节点:命名(唯一)
    // 参数1和参数2 后期为节点传值会使用
    // 参数3 是节点名称，是一个标识符，需要保证运行后，在 ROS 网络拓扑中唯一
    ros::init(argc,argv,"pub");
    //3.实例化 ROS 句柄
    ros::NodeHandle nh;//该类封装了 ROS 中的一些常用功能

    //4.实例化 发布者 对象
    //泛型: 发布的消息类型
    //参数1: 要发布到的话题
    //参数2: 队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic",1000);

    //5.组织被发布的数据，并编写逻辑发布数据
    //数据(动态组织)
    std_msgs::String msg;
    
    ros::Rate rate(10);
   

    //节点不死
    while (ros::ok())
    {
        
         std::string str;
        ROS_INFO("输入的小写英文");
        std::getline(std::cin,str);
        msg.data=str;
        pub.publish(msg);

    }


    return 0;
}

/订阅方
#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p){
    ROS_INFO("转化为大写字母为:%s",msg_p->data.c_str());
    // ROS_INFO("我听见:%s",(*msg_p).data.c_str());
}
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"sub");
    //3.实例化 ROS 句柄
    ros::NodeHandle nh;

    //4.实例化 订阅者 对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("out_topic",doMsg);
    //5.处理订阅的消息(回调函数)

    //     6.设置循环调用回调函数
    ros::spin();//循环读取接收的数据，并调用回调函数处理

    return 0;
}
