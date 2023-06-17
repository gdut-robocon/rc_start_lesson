#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"service_call");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    client.waitForExistence();
    turtlesim::Spawn spawn;
    spawn.request.x =1.0;
    spawn.request.y =1.0;
    spawn.request.theta =1.57;
    spawn.request.name ="turtle2";
    //ros::service::waitForService("/spawn");
    bool flag = client.call(spawn);
    if(flag)
    {
        ROS_INFO("乌龟生成成功，名字叫：%s",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("乌龟生成失败");
    }
    return 0;
}