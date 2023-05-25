#include "ros/ros.h"
#include "turtlesim/Spawn.h"

std::string turtle_name;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        ROS_INFO("请输入turtle名");
    }else{
        turtle_name = argv[1];
    }
    

    setlocale(LC_ALL,"");
    ros::init(argc,argv,"add_turtle");
    
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    
    turtlesim::Spawn spawn;

    spawn.request.name = turtle_name;
    spawn.request.x = 2;
    spawn.request.y = 2;
    spawn.request.theta = 1.57;

    ros::service::waitForService("spawn");
    bool flag = client.call(spawn);
    if(flag){
        ROS_INFO("创建%s成功!",spawn.response.name.c_str());
    }else{
        ROS_INFO("创建失败!");
    }
}