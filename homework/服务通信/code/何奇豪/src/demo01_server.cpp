#include "ros/ros.h"
#include "plumbing_server_client/AddTwoInts.h"
/* 
   服务端实现：解析客户端提交的数据，并运算再产生响应
        1.包含头文件；
        2.初始化ROS节点；
        3.创建节点句柄；
        4.创建一个服务对象；
        5.处理请求并产生响应；
        6.spin()；
*/

bool doNums(plumbing_server_client::AddTwoInts::Request &request,
            plumbing_server_client::AddTwoInts::Response &response){
    //1.处理请求
    int a = request.a;
    int b = request.b;
    ROS_INFO("收到的请求数据:a = %d,b = %d",a,b);
    //2.组织相应
    int sum = a + b;
    response.sum = sum;
    ROS_INFO("求和结果:sum = %d",sum);
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化ROS节点；
    ros::init(argc,argv,"server");//节点名称需要保证唯一
    //3.创建节点句柄；
    ros::NodeHandle nh;
    //4.创建一个服务对象；
    ros::ServiceServer server = nh.advertiseService("add_two_ints",doNums);
    ROS_INFO("服务器端启动");
    //5.处理请求并产生响应；
    //6.spin()；
    ros::spin();
    return 0;
}