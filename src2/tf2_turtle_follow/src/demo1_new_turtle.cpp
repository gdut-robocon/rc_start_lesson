#include "ros/ros.h"
#include "turtlesim/Spawn.h"

/*
        服务话题 /spawn
        服务消息类型 turtlesim/Spawn
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"turtle_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = 5.0;
    spawn.request.y = 2.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
    client.waitForExistence();
    bool flag = client.call(spawn);
    if (flag)
    {
        ROS_INFO("生成的小乌龟名字为:%s",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("生成失败！");
    }
    
    return 0;
}
