#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"
/*
    服务器端实现
    1.照例初始化
    2.创建服务器
    3.处理请求产生响应
    4.spin()

*/

bool doNums(plumbing_server_client::Addints::Request &request,
            plumbing_server_client::Addints::Response &response){

        int a = request.a;
        int b = request.b;

    ROS_INFO("服务器接收到的请求数据为:num1 = %d, num2 = %d",a, b);

    //逻辑处理
    if (a < 0 || b < 0)
    {
        ROS_ERROR("提交的数据异常:数据不可以为负数");
        return false;
    }

    //如果没有异常，那么相加并将结果赋值给 resp
    response.sum = a + b;
    return true;

}
int main(int argc, char *argv[])
{   ros::init(argc,argv,"Servant");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("Addints",doNums);

    ros::spin();
    
    return 0;
}
