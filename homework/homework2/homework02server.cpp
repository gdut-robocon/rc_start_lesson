#include "ros/ros.h"
#include "ros_tutorials_service/AddTwoInts.h"   
bool doadd(ros_tutorials_service::AddTwoInts::Request &those,   
           ros_tutorials_service::AddTwoInts::Response &these)  
    int num1 = those.a;  
    int num2 = those.b;
    ROS_INFO("two data: num1 = %d, num2 = %d",num1,num2);

    int sum = num1 + num2;
    these.sum = sum;    
    ROS_INFO("planation: sum = %d",sum);

    return true;  
}


int main(int argc,char *argv[])
{
    ros::init(argc,argv,"baiduren");  

    ros::NodeHandle x;  

    ros::ServiceServer bdr = x.advertiseService("add_two_ints",doadd); 

    ROS_INFO("linkstart");

    ros::spin();   

    return 0;
}