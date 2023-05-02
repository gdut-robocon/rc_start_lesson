#include "ros/ros.h"
#include "rc_homework1/addTwoInts.h"

// bool 返回值由于标志是否处理成功
bool doReq(rc_homework1::addTwoInts::Request& req,
          rc_homework1::addTwoInts::Response& resp){
    int num1 = req.num1;
    int num2 = req.num2;

    ROS_INFO("服务器接收到的请求数据为:num1 = %ld, num2 = %ld",num1, num2);

    //逻辑处理
    if (num1 < 0 || num2 < 0)
    {
        ROS_ERROR("提交的数据异常:数据不可以为负数");
        return false;
    }

    //如果没有异常，那么相加并将结果赋值给 resp
    resp.sum = num1 + num2;
    return true;


}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"AddInts_Server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("add_two_ints",doReq);
    ROS_INFO("服务已经启动....");
    ros::spin();
    return 0;
}
