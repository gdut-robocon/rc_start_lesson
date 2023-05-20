题目：编写一个ROS节点，读取一个yaml文件中的参数，并将其发布到一个名为“yaml_param”的话题上。同时，创建一个订阅者节点，接收“yaml_param”话题的消息，并将其打印到终端上。

具体要求：

1. 发布者节点名称为“yaml_publisher”，订阅者节点名称为“yaml_subscriber”。

2. 发布者节点读取一个名为“my_param”的参数，该参数从一个名为“my_yaml.yaml”的yaml文件中读取。该参数应该是一个字符串类型。

3. 发布者节点将参数值发布到一个名为“yaml_param”的话题上，消息类型为std_msgs::String。


#include <ros/ros.h>
#include <std_msgs/String.h>
#include <yaml-cpp/yaml.h>
#include <fstream>

int main(int argc, char **argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "yaml_publisher");
    ros::NodeHandle nh;
    // 创建一个发布者，发布类型的消息到“yaml_param”话题
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param", 10);
    // 设置发布频率为10Hz
    ros::Rate rate(10);
    // 读取yaml文件中的参数
    YAML::Node node = YAML::LoadFile("params.yaml");
    // 循环发布参数到话题上
    while (ros::ok()) {
        std_msgs::String msg;
        msg.data = YAML::Dump(node);
        pub.publish(msg);
        rate.sleep();
    }
    return 0;
}
```



```订阅
#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(const std_msgs::String::ConstPtr& msg) {
    // 打印接收到的消息
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "yaml_subscriber");
    ros::NodeHandle nh;
    // 创建一个订阅者，订阅“yaml_param”话题，指定回调函数为callback
    ros::Subscriber sub = nh.subscribe("yaml_param", 10, callback);
    // 循环等待消息
    ros::spin();
    return 0;
}
```

