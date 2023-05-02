#include "ros/ros.h"
#include "homework_vscode/NIVA.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    if(argc != 3) 
    {
        ROS_INFO("提交的参数个数不足");
        return 1;
    }
    ros::init(argc,argv,"question");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<homework_vscode::NIVA>("AddTwoInts");
    homework_vscode::NIVA helper;
    helper.request.a = atoi(argv[1]);
    helper.request.b = atoi(argv[2]);
    //等待服务器响应
    ros::service::waitForService("AddTwoInts");
    bool flag = client.call (helper);
    if (flag)
    {
        ROS_INFO("响应成功");
        ROS_INFO("结果是:%d",helper.response.sum);
    }
    else
    {
        ROS_INFO("响应失败");
    }
    
    return 0;
}
