#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_turtle");
    ros::NodeHandle co;

    ros::ServiceClient t = co.serviceClient<turtlesim::Spawn>("/spawn");

    ros::service::waitForService("/spawn");

    turtlesim::Spawn spawn_msg;

    spawn_msg.request.x = 2.0;
    spawn_msg.request.y = 2.0;
    spawn_msg.request.theta = 1.57;
    spawn_msg.request.name = "turtle2";

    bool judge = t.call(spawn_msg);

    if(judge)
    {
        ROS_INFO("新的乌龟生成，名字: %s",spawn_msg.response.name);
    }else{
        ROS_INFO("乌龟生成失败！！！");

    } 
    
    return 0;
}
