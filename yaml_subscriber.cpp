#include <ros/ros.h>
#include <std_msgs/String.h>

void doMsg(const std_msgs::String::ConstPtr& msg_p)
{
    //the type of msg is"std_msgs::string
    std_msgs::String msg;
    msg.data = msg_p->data;
    ROS_INFO("the msg is:%s",msg.data.c_str());

    // exchange it into the toupper
   
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "yaml_subscriber");   
    ros::NodeHandle nh;
    // and subscribe the topic
    ros::Subscriber sub = nh.subscribe("my_param", 1000, doMsg);

    ros::spin();

    return 0;
}