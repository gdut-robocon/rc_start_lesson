#include "ros/ros.h"
#include "add_two_ints/AddInts.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"add_two_ints_client");

    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<add_two_ints::AddInts>("AddTwoInts");
    
    ROS_INFO("客户端已经启动...");

    add_two_ints::AddInts ai;
    ai.request.a = atoi(argv[1]);
    ai.request.b = atoi(argv[2]);

    bool flag = client.call(ai);

    if (flag){
        ROS_INFO("响应成功！");
        ROS_INFO("响应结果 = %d",ai.response.sum);
    }else{
        ROS_INFO("响应失败！");
    }

    return 0;
}