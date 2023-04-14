#include "ros/ros.h"
#include "ros_tutorials_service/AddTwoInts.h"

/*
  服务端实现：解析客户端提交的数据，并运算再产生响应
    1.包含头文件
    2.初始化ROS节点
    3.创建节点句柄
    4.创建一个服务对象
    5.处理请求并产生响应
    6.spin()

 */

 //5.处理请求并产生响应
bool doNums(ros_tutorials_service::AddTwoInts::Request& request,
    ros_tutorials_service::AddTwoInts::Response& response) {

    int num1 = request.a;
    int num2 = request.b;
    int sum = num1 + num2;
    response.sum = sum;
    return true;

}


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    //初始化ros节点
    ros::init(argc, argv, "add_tw0_ints");
    //创建ros句柄
    ros::NodeHandle nh;
    //创建一个服务对象
    ros::ServiceServer serve = nh.advertiseService("add_tw0_ints", doNums);
    ros::spin();
    return 0;
}
