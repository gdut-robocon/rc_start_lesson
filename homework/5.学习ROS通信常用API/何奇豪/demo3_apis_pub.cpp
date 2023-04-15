#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
/*
      发布方实现：
            1.包含头文件；
              ROS中文本类型  ---> std_msgs/String.h
            2.初始化ros节点；
            3.创建节点句柄；
            4.创建发布者对象；
            5.编写发布逻辑并发布数据；
*/

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");
    //2.初始化ROS节点
    ros::init(argc,argv,"erGouZi",ros::init_options::AnonymousName);//避免节点重复启动，为节点名称加一个随机数后缀
    //argc:传入参数个数
    //argv[]:传入参数数值
    //节点名称
    //节点启动项：为节点名称后缀一个随机数
    //3.创建节点句柄；
    ros::NodeHandle nh;
    //4.创建发布者对象；
    /* 
        作用：创建发布者对象

        模板：被发布的消息的类型

        参数：
            1.话题名称
            2.队列长度
            3.latch(可选)   如果设置为true,会保存发布方最后一条消息，并且新的订阅对象连接到发布方时，发布方会将这条消息发送给订阅者           
        使用:
            latch设置为true的作用
            以静态地图发布为例，方案一：可以使用固定频率发布地图数据，但是效率低；方案二可以将地图发布对象的latch设置为true，并且发布方只发送一次数据，每当订阅者连接时，就可以将地图数据发送给订阅者（只发送一次），这样就提高了数据的发送效率
    */
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10,true);
    //5.编写发布逻辑并发布数据；
    //要求以 10HZ 的频率发布数据，并且文本后添加编号
    //先创建被发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(1);//每秒次数
    //设置编号
    int count = 0;
    //编写循环，循环发布数据
    ros::Duration(3).sleep();
    while (ros::ok())
    { 
        //如果计数器 >= 50,那么关闭节点
        if(count >= 50)
        {
            ros::shutdown();
        }
        //------------------------
        count++;
        //实现字符串拼接数字
        std::stringstream ss;
        ss <<"hello ---> " << count;
        // msg.data = "hello";
        msg.data = ss.str();
        // if(count <= 10)
        // {
        // pub.publish(msg);
        // //添加日志：
        // ROS_INFO("发布的数据是:%s",ss.str().c_str());
        // } 

       
        pub.publish(msg);
        ROS_INFO("发布的数据是:%s",ss.str().c_str());
        
        rate.sleep();

        ros::spinOnce();//官方建议，处理回调函数
        ROS_INFO("一轮回调执行完毕--");
    }
    return 0;
}