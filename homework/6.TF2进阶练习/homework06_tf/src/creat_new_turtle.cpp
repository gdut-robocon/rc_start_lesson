#include "ros/ros.h"
#include "turtlesim/Spawn.h"
// 动态传入乌龟的名字

static std::string turtle_name;
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");  //解决中文乱码
    ros::init(argc,argv,"new_turtle");   //初始化ROS节点
     ros::NodeHandle nh;   //创建ROS句柄
    if(argc!=2){
        ROS_INFO("请输入正确的参数!");
    }else{
        turtle_name=argv[1];    //通过传参为新乌龟命名
    }
    //创建客户端
    ros::ServiceClient client=nh.serviceClient<turtlesim::Spawn>("/spawn");
    //等待服务启动
    ros::service::waitForService("/spawn");
    //发布请求 
    turtlesim::Spawn spawn;
    spawn.request.name=turtle_name;
    spawn.request.x=2;
    spawn.request.y=3;
    spawn.request.theta=0;
   bool flag=client.call(spawn);
   //处理响应结果
      if(flag){
        ROS_INFO("%s已生成",spawn.request.name.c_str());
      }else{
           ROS_INFO("乌龟生成失败!");
      }
  
    return 0;
}
