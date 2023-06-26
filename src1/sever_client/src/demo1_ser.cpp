#include "ros/ros.h"
#include "sever_client/AddInts.h"

//回调函数处理响应数据
bool doNums(sever_client::AddInts::Request &request,
            sever_client::AddInts::Response &response)
{
    int num1 = request.num1;
    int num2 = request.num2;
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("两个数据之和为 sum = %d",sum);
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"server");
    //实例化ros句柄
    ros::NodeHandle nh;
    //实例化服务对象
    ros::ServiceServer server = nh.advertiseService("addsum",doNums);
    ROS_INFO("服务通信开始");
    //回头
    ros::spin();
    return 0;
}
