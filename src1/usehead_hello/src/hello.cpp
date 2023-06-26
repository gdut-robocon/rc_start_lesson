#include "ros/ros.h"
#include "usehead_hello/hello.h"

namespace hello_ns
{
    void Hello::hello()
    {
        ROS_INFO("hello!");
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"head_hello");
    ros::NodeHandle nh;
    hello_ns::Hello hello;
    hello.hello();
    
    return 0;
}


