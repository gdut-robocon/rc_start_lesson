#include "ros/ros.h"

/* 
   ROS中日志：
      演示不同级别日志的基本使用
*/

int main (int argc,char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_log");
    ros::NodeHandle nh;

    //日志输出
    ROS_DEBUG("调试信息");  //不会打印在控制台
    ROS_INFO("一般信息");
    ROS_WARN("警告信息");
    ROS_ERROR("错误信息");
    ROS_FATAL("严重错误");

    return 0;
}