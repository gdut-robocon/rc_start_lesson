#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char  *argv[])
{
 setlocale(LC_ALL,"");
  ros::init(argc,argv,"input_topic");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param",10);
  std_msgs::String msg;
  int count = 0;
   ros::Rate r(5);
  while (ros::ok())
  {
    rosparam load my_yaml.yaml
     std::stringstream ss;
    ss <<"my_param> " <<count;
    msg.data = ss.str();
    pub.publish(msg);
     ROS_INFO("发送的消息:%s",msg.data.c_str());
    r.sleep();
    count++;
    
    ros::spinOnce();
  } 
  return 0;
}