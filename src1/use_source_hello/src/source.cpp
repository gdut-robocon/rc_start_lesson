#include "ros/ros.h"
#include "use_source_hello/hello.h"

namespace hello_ns
{
    void Hello::hello()
    {
        ROS_INFO("hello!");
    }
}