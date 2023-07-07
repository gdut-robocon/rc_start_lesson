#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"publisher");
    //实例化ros句柄
    ros::NodeHandle nh;
    //实例化话题对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("topic",10);
    //创建发布信息
    std_msgs::String msg;
    //计数
    int count = 0;
    ros::Rate rate(10);
    //当结点不死时执行循环
    while(ros::ok())
    {
        count++;
        //定义拼接字符串对象ss
        std::stringstream ss;
        //将字符串与数字进行拼接
        ss << "起佳是炜佳他爹 -->" << count;
        msg.data = ss.str();
        //发布信息
        pub.publish(msg);
        //休眠
        rate.sleep();
        //输出日志
        ROS_INFO(" %s",ss.str().c_str());
    }
    return 0;
}
