#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"set_turtle");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
     ros::service::waitForService("/spawn");
     turtlesim::Spawn spawn;
    spawn.request.x = 2.0;
    spawn.request.y = 2.0;
    spawn.request.theta = 2.0;
    spawn.request.name = "t1";
     bool flag = client.call(spawn);
     if (flag)
    {
        ROS_INFO("乌龟生成成功,名称:%s",spawn.response.name.c_str());
    } else {
        ROS_INFO("乌龟生成失败");
    }

    return 0;
}