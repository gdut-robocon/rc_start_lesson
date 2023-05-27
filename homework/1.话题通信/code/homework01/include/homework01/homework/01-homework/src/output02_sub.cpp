#include "ros/ros.h"
#include "std_msgs/String.h"  

 //可有可无的源文件

void printf(const std_msgs::String::ConstPtr &msg){
   
    ROS_INFO("订阅修改的数据:%s",msg->data.c_str());  //智能指针

}

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"End");

    ros::NodeHandle n;  
  
    ros::Subscriber sub = n.subscribe("output_topic",10,printf);    
   
    ros::spin(); 

    return 0;
}