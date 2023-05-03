#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"

void Callback(const  std_msgs::String::ConstPtr& msg) {
    ROS_INFO("接收到的消息为：%s", msg->data.c_str());
}
int main(int argc, char* argv[])
{
    //订阅方实现
      //解决乱码
    setlocale(LC_ALL, "");
    //初始化ros节点
    ros::init(argc, argv, "yaml_subscriber");
    //创建ros句柄
    ros::NodeHandle nh;
    //创建订阅对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("yaml_param", 10, Callback);
    //回调函数
    ros::spin();
    return 0;
}
