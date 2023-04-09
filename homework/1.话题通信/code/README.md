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

大家参考一下即可，其实主要实现是在订阅方而不是发布哦。

发布方大家就自己去搞搞吧
