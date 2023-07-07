#include "ros/ros.h"
#include "homework2/AddTwoInts.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //argc中存储的是参数的数量，其中有变量名和两个传进去的数字，所以是三个
    if(argc != 3)
    {
        ROS_INFO("参数数量错误！");
        return 1;
    }
    //初始化ros节点
    ros::init(argc,argv,"cli");
    //实例化ros句柄
    ros::NodeHandle nh;
    //实例化客户对象
    ros::ServiceClient client = nh.serviceClient<homework2::AddTwoInts>("add_two_ints");
    //实例化参数对象
    homework2::AddTwoInts ha;
    //argv中存储的是参数的内容，第一个是变量名，所以数字是从索引为1的地方开始的
    //atoi能将字符串转化为整数
    ha.request.a = atoi(argv[1]);
    ha.request.b = atoi(argv[2]);
    //判断是否成功响应
    bool flag = client.call(ha);
    if(flag)
    {
        ROS_INFO("响应成功！");
        ROS_INFO("响应结果为：%ld",ha.response.sum);
    }
    else
    {
        ROS_INFO("响应失败！");
    }

    return 0;
}
