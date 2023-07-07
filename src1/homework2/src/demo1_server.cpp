#include "ros/ros.h"
#include "homework2/AddTwoInts.h"

bool doNums(homework2::AddTwoInts::Request &request,
            homework2::AddTwoInts::Response &response)
{
    long a = request.a;
    long b = request.b;
    long sum = a + b;
    response.sum = sum;
    ROS_INFO("两个数据之和为 sum = %ld",sum);
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"ser");
    //实例化ros句柄
    ros::NodeHandle nh;
    //实例化服务对象
    ros::ServiceServer server = nh.advertiseService("add_two_ints",doNums);
    ROS_INFO("服务通信开始");
    //回头
    ros::spin();
    return 0;
}

