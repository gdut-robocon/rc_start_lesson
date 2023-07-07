#include "ros/ros.h"
#include <yaml-cpp/yaml.h>
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_publisher");
    ros::NodeHandle nh;
    //实例化发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param",10);
    //读取发布信息
    std_msgs::String my_param;
    std::string msg;
    nh.getParam("my_param",msg);
    my_param.data = msg;
    //ROS_INFO("%s",my_param.data.c_str());
    ros::Rate rate(2);

    while(ros::ok())
    {
        pub.publish(my_param);
        ROS_INFO("已发送：%s",my_param.data.c_str());
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
    
}
