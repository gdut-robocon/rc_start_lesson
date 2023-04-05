#include "ros/ros.h"
/*
    需要实现参数的新增与修改
    需求：
        1. 发布者节点名称为“yaml_publisher”，订阅者节点名称为“yaml_subscriber”。

        2. 发布者节点读取一个名为“my_param”的参数，该参数从一个名为“my_yaml.yaml”的yaml文件中读取。该参数应该是一个字符串类型。

        3. 发布者节点将参数值发布到一个名为“yaml_param”的话题上，消息类型为std_msgs::String。

        4. 订阅者节点订阅“yaml_param”话题，接收发布者发布的消息，并将其打印到终端上。
    实现：//增加参数
        ros::Nodehandle
            setParam("健",值)
        ros::param
            set（"健",值）
        //读取信息
        nh.getParam("/my_yaml.yaml/my_param",my_param);
    修改，只需要继续调用此函数，保证健不变，值会覆盖
*/

int main(int argc,char *argv[])
{
    //初始化ROS节点
    ros::init(argc,argv,"yaml_publisher");
    //创建ROS节点句柄
    ros::NodeHandle nh;
    //读取参数
    std::string my_param;
    bool result = nh.getParam("/my_yaml.yaml/my_param",my_param);
    if(result)
    {
        ROS_INFO("读取到的信息是：%s",my_param);
    }else{
        ROS_INFO("读取失败！");
    }
    //参数增------------------------------
    //方案1：nh
    nh.setParam("yaml_param",my_param);
    
    /*方案2：ros::param
    ros::param::set("type_param","xiaoBai");
    ros::param::set("radius_param",0.15);
    */
    
    /*参数改------------------------------(与增同理)
    方案1：nh
    nh.setParam("radius",0.2);
    方案2：ros::param
    ros::param::set("radius_param",0.25);
    */

    return 0;
}