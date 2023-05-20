#include<ros/ros.h>
#include <std_msgs/String.h>


int main(int argc, char  *argv[])
{
   setlocale(LC_ALL,"");
   ros::init(argc,argv,"yaml_publisher");
   ros::NodeHandle nh;
   ros::Publisher pub=nh.advertise<std_msgs::String>("yaml_param",10);
   std::string msg_front;
   std_msgs::String msg;
   nh.getParam("my_param",msg_front);
   msg.data=msg_front;
   pub.publish(msg);
   ros::Rate rate(10);
   int count=0;
    
   while(ros::ok())
   {
    count++;
    pub.publish(msg);
    ROS_INFO("发布的数据是:%s %d",msg.data.c_str(),count);
    rate.sleep();
    ros::spinOnce();
   }
    return 0;
}
