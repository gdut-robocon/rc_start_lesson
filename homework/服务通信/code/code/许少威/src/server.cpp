#include "ros/ros.h"
#include "add_two_ints/AddInts.h"

bool doReq(add_two_ints::AddInts::Request & req,
        add_two_ints::AddInts::Response & resp){
    
    int a = req.a;
    int b = req.b;

    if (a < 0 || b < 0 ) {
        ROS_INFO("请求失败！");
        return false;
    }
    resp.sum = a + b;
    ROS_INFO("收到的数据为: a = %d, b = %d",a,b);
    ROS_INFO("返回值为: %d",resp.sum);
    return true;
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"add_two_ints_server");

    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("AddTwoInts",doReq);
    ROS_INFO("服务器已经启动...");

    ros::spin();

    return 0;
}