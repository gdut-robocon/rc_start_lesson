\\本文件是对“常用API”中时间部分的运用，可以测试连续发布消息的间隔时间
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
void doSomeThing(const ros::TimerEvent &event)
{int a=0;
  
  while (a<10)
  {
     
     ros::Time right_now = ros::Time::now();
     ROS_INFO("当前时刻:%f",right_now.toSec()); 
    a++;
  } 
}
int main(int argc, char  *argv[])
{
 setlocale(LC_ALL,"");
  ros::init(argc,argv,"time");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::String>("topic",10);
  std_msgs::String msg;
  ros::Timer timer = nh.createTimer(ros::Duration(5),doSomeThing);
  ros::spin();
    
return 0;
}