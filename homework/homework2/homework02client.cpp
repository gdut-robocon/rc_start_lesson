#include "ros/ros.h"
#include "ros_tutorials_service/AddTwoInts.h"

int main(int argc,char *argv[])
{

    ROS_INFO("serverrequest:");

    if(argc != 3)    
    {
        ROS_INFO("argc error!");
        return 1; 
    }

    ros::init(argc,argv,"Clientzbw");

    ros::NodeHandle h;

    ros::ServiceClient shizuka = h.serviceClient<ros_tutorials_service::AddTwoInts>("add_two_ints");  

    ros_tutorials_service::AddTwoInts need;   
    need.request.a = atoi(argv[1]);
    need.request.b = atoi(argv[2]);   

    shizuka.waitForExistence();   

    bool sign = shizuka.call(need);   

    if(sign)  
    {
        ROS_INFO("success");
        ROS_INFO("result = %d",need.response.sum);  
    }else{
        ROS_INFO("fail...");
    }

    return 0;
}