#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"


int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"param_cpp");
    setlocale(LC_ALL,"");
    ros::NodeHandle nh;  
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param", 10);
    std_msgs::String msgs;      
    std::string getparam = "meishoudao";    //没收到消息就回复“meishoudao”
    nh.getParamCached("my_yaml", getparam);   
    msgs.data = getparam;   
    ros::Rate rate(1);
     while (ros::ok) 
     {

        ROS_INFO("发布的消息为：%s", msgs.data.c_str());
        pub.publish(msgs);
        rate.sleep();
    }
    return 0;
}
