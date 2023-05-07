#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char *argv[])
{
    ros::init(argc,argv,"yaml_publisher");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("my_param",10);
    std_msgs::String msg;
    bool flag0 = nh.getParam("my_param",msg.data);
    if(flag0)
    {
        ROS_INFO("it's succeesful to get ");

    }else{
        ROS_INFO("it's fail to get");
    }
    return 1;
    ros::Rate rate(1);
    
    while (ros::ok())
    {
        pub.publish(msg);
        ROS_INFO("the param is:%s",msg.data.c_str());
        rate.sleep();
        ros::spin();

    }
    
    return 0;
}
