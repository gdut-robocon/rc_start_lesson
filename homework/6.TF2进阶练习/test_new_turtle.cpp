#include "ros/ros.h"
#include "turtlesim/Spawn.h"

/*
    需求：向服务器发送请求，生成一只新的乌龟
        话题：/spawm
        消息：/turtlesim/Spawm

(
    1.包含头文件
    2.初始化ros节点
    3.创建节点句柄
    4.创建客户端对象
    5.组织数据并发送
    6.处理数据并响应


*/
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"service_call");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");   //此处节点名称必须与原先/turtlesim/**下的子文件的文件名一致
    turtlesim::Spawn spawm;
    spawm.request.x = 1.0;
    spawm.request.y = 4.0;
    spawm.request.theta = 1.57;
    spawm.request.name="turtle2";

    //判断服务器状态
    client.waitForExistence();
    bool flag = client.call(spawm);
    if(flag == 1)
    {
        ROS_INFO("请求生成乌龟成功，乌龟叫%s",spawm.response.name.c_str());
    }
    else
    {
        ROS_INFO("请求失败");
    }
    
    return 0;
}
