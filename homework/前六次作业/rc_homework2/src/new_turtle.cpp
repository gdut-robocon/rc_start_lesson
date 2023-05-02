#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{   
    // 设置编码
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"new_turtle");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    ros::service::waitForService("/spawn");
    turtlesim::Spawn spawn;
    // 填入小乌龟生成的信息
    spawn.request.name="turtle2";
    spawn.request.theta=1.57;
    spawn.request.x=1;
    spawn.request.y=1;

    // 判断是否请成功
    bool flag = client.call(spawn);
    if(flag){
        ROS_INFO("生成新乌龟：%s",spawn.response.name.c_str());
    }else{
        ROS_INFO("生成失败！");
    }

    ros::spin();
    return 0;
}
