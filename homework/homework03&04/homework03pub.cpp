#include <ros/ros.h>
#include <std_msgs/String.h>
#include <yaml-cpp/yaml.h>

int main(int argc, char** argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "yaml_publisher");
    ros::NodeHandle nh;

    // 从yaml文件中读取参数
    YAML::Node params = YAML::LoadFile("/path/to/my_yaml.yaml");
    std::string my_param = params["my_param"].as<std::string>();

    // 创建话题发布者
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param", 10);

    // 发布参数值
    ros::Rate rate(10); // 10 Hz
    while (ros::ok()) {
        std_msgs::String msg;
        msg.data = my_param;
        pub.publish(msg);
        rate.sleep();
    }

    return 0;
}