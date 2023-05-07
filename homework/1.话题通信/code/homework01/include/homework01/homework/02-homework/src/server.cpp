#include "ros/ros.h"
#include "ros_tutorials_service/AddTwoInts.h"   //引入的头文件，srv定义了些整形,"包名+srv文件名"

bool doadd(ros_tutorials_service::AddTwoInts::Request &those,   //引用只在此函数内起接受数据的作用
           ros_tutorials_service::AddTwoInts::Response &these)  //回调函数，另一边先给两个值，然后这边接收
{
    int num1 = those.a;  //接收request下的数据a
    int num2 = those.b;
    ROS_INFO("客户发过来的两个数据是: num1 = %d, num2 = %d",num1,num2);

    int sum = num1 + num2;
    these.sum = sum;    //把服务处理的值赋值给response下的数据sum
    ROS_INFO("我们给出的方案是: sum = %d",sum);

    return true;  //bool类型，要返回1/0，另一边可接受，然后用if来判断是否响应成功
}


int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"company_jdfx");  //节点只能有一个，节点句柄和创建的服务对象可以有多个

    ros::NodeHandle k;  //已被封装，走个过场，名称可以随便取

    ros::ServiceServer jdfx = k.advertiseService("add_two_ints",doadd); //定义一个要提供服务的对象jdfx

    ROS_INFO("服务器正式启动");

    ros::spin();   //开启回调函数

    return 0;
}