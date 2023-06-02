#include "ros/ros.h"
#include "homework_vscode/NIVA.h"

bool doNums(homework_vscode::NIVA::Request &request,
            homework_vscode::NIVA::Response &response)
{
    int a = request.a;
    int b = request.b;
    ROS_INFO("接收到参数:a = %d,b = %d",a,b);
    int sum = a+b;
    response.sum = sum;
    ROS_INFO("结果是:sum = %d",sum);
    return true;
}


int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"add_two_ints");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("AddTwoInts",doNums);
    ROS_INFO("服务器启动");
    ros::spin();
    return 0;
}
