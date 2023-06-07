#include"ros/ros.h"
#include"turtlesim/Spawn.h"
int main(int argc,char *argv[]){
    ros::init(argc,argv,"service_call");
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x=1.0;
    spawn.request.y=4.0;
    spawn.request.theta=1.57;
    spawn.request.name="turtle2";
    client.waitForExistence();
    bool flag=client.call(spawn);
    if (flag){
        ROS_INFO("Successful!the name of new turtle is:%s",spawn.response.name.c_str());
    }else{
        ROS_INFO("Fail...");
    }
    return 0;

}