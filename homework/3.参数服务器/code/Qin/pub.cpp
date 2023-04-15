
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"




int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "");//解决中文乱码问题
    //发布方实现
    ros::init(argc, argv, "yaml_publister");
    ros::NodeHandle nh;  
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param", 10);

    std_msgs::String upper;      //创建发布对象
    std::string getparam = "false";    //设置变量储存字符串,初始值为false
    ros::param::get("my_yaml", getparam);   //将获取的参数赋值给getparam,若获取失败,则输出false
    upper.data = getparam;   //将getparam获取到的值给发布对象
    ros::Rate rate(1);
    //发布消息
    while (ros::ok) {

        ROS_INFO("发布的消息为：%s", upper.data.c_str());
        pub.publish(upper);
        rate.sleep();
    }

    return 0;
}
