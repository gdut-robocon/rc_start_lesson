#include<ros/ros.h>
#include<turtlesim/Spawn.h>

//生成第二只乌龟
//关键是调用spawn函数
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"set_turtle");
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<turtlesim::Spawn>("/spawn");
    //调用内置客户端spawn函数
    turtlesim::Spawn spawn;
    spawn.request.x=2.0;
    spawn.request.y=4.0;
    spawn.request.theta=1.57;
    spawn.request.name="turtle2";
    //设置乌龟相关参数
    ros::service::waitForService("/spawn");
    bool flag=client.call(spawn);
    if(flag)
    {
        ROS_INFO("乌龟生成成功，新乌龟叫：%s",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("生成乌龟失败。");
    
    }
    return 0;
}