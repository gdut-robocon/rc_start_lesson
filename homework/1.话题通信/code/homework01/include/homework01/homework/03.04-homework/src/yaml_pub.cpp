#include "ros/ros.h"
#include "std_msgs/String.h"

int main (int argc,char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_publisher");
    ros::NodeHandle love;

    ros::Publisher jdfx = love.advertise<std_msgs::String>("yaml_param",10);

    std::string message ;
    bool p = love.getParam("my_param",message);
    if(p)
    {
      ROS_INFO("接收成功！");
    }else{
      ROS_INFO("接收失败！");
    }

      ROS_INFO("接收成功！");
    std_msgs::String msg ;
    msg.data = message;

    while(ros::ok())
    {
      jdfx.publish(msg);
      ROS_INFO("发布的数据是：%s",message.c_str()); 
      ros::Rate r(1);
      r.sleep();
    }

    ros::spinOnce();

    return 0;
}