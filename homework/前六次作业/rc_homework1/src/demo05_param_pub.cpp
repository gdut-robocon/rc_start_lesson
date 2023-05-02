#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"yaml_publisher");
    setlocale(LC_ALL,"");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param",10);
    std_msgs::String msg;
    bool flag = nh.getParam("my_yaml",msg.data);
    if(flag){
        ROS_INFO("获取成功");
    }else{
        ROS_INFO("获取失败");
    }
    ros::Rate r(1);

    while (ros::ok())
    {
        pub.publish(msg);
        ROS_INFO("打印的消息是：%s",msg.data.c_str());
        r.sleep();
       ros::spinOnce();
    }

    return 0;
}