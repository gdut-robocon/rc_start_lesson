#include "ros/ros.h"
#include "use_source_hello/hello.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"source_hello");
    hello_ns::Hello hello;
    hello.hello();
    return 0;
}
