#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Received: %s", msg->data.c_str());
}

int main(int argc, char** argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "yaml_subscriber");
    ros::NodeHandle nh;

    // 创建话题订阅者
    ros::Subscriber sub = nh.subscribe("yaml_param", 10, callback);

    // 进入事件循环
    ros::spin();

    return 0;
}
