#include"ros/ros.h"
#include"turtlesim/Spawn.h"
/*
   功能：创建一个乌龟 
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"spawn_test");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");  //璁㈤槄spawn鏈嶅姟鑺傜偣
    turtlesim::Spawn spawn;  //创建spawn对象 
    spawn.request.x =1.0;
    spawn.request.y =4.0;
    spawn.request.theta =1.57;
    spawn.request.name ="turtle2";  //赋予位姿信息和名字 
    ros::service::waitForService("/spawn");  //等待响应 
    bool flag = client.call(spawn);  //flag返回是响应结果 
    if(flag){
        ROS_INFO("build success, name:%s",spawn.response.name.c_str());
    }
    else{
        ROS_INFO("build fail");
    }
    ros::spinOnce();  //回调 
    return 0;
}
