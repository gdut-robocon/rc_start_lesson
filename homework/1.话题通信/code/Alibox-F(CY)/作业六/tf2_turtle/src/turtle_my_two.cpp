/*
    生成一只小乌龟
    准备工作:
        1.服务话题 /spawn
        2.服务消息类型 turtlesim/Spawn
        3.运行前先启动 turtlesim_node 节点

    实现流程:
        1.初始操作
        2.创建 service 客户端
        3.发送请求（判断状态）
        4.处理响应

*/

#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    
    ros::init(argc,argv,"turtle2_crate");
    ros::NodeHandle nh;
    // 创建 service 客户端
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    // client.waitForExistence();
    // ros::service::waitForService("/spawn");
    // 发送请求
    turtlesim::Spawn spawn;
    spawn.request.x = 2.0;
    spawn.request.y = 1.0;
    spawn.request.theta = 1.57;//转向一半（最大3.14）
    spawn.request.name = "turtle2";

    // 判断服务状态
    client.waitForExistence();
    bool flag = client.call(spawn);
    // 处理响应结果
    if (flag)
    {
        ROS_INFO("新的乌龟生成成功:%s",spawn.response.name.c_str());
    } else {
        ROS_INFO("乌龟生成失败！");
    }


    return 0;
}
