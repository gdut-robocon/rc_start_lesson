#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"output_topic");
    ros::NodeHandle nh;
    ros::Publisher output_pub=nh.advertise<std_msgs::String>("string_converter",1000);
    std_msgs::String msg;
    ros::Rate loop_rate(10);
    
    
    while(ros::ok())
    {
        std_msgs::String output_msg;
        std::string input_string;
        std::cout<<"输入字符来发布：";
        std::getline(std::cin,input_string);
        std::transform(input_string.begin(), input_string.end(), input_string.begin(), [](unsigned char c){ return std::toupper(c); });
        output_msg.data = input_string;
        output_pub.publish(output_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;

}
