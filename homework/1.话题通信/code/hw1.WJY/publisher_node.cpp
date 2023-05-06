#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "string_converter_publisher");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic", 1000);

    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        // 读取输入字符串
        std::string input_str;
        std::cout << "Please enter a string: ";
        std::getline(std::cin, input_str);

        // 发布输入字符串
        std_msgs::String msg;
        msg.data = input_str;
        pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
