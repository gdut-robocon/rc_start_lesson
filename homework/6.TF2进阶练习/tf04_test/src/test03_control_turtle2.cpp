#include"ros/ros.h"
#include"tf2_ros/transform_listener.h"
#include"tf2_ros/buffer.h"
#include"geometry_msgs/PointStamped.h"
#include"tf2_geometry_msgs/tf2_geometry_msgs.h"
#include"geometry_msgs/TransformStamped.h"
#include"geometry_msgs/Twist.h"
// 订阅方实现：1计算son1与son2的相对关系 2计算son1中的某个坐标点在son2中的坐标值
// 流程：1包含头文件
// 2编码 初始化 nodehandle
// 3创建订阅对象
// 4编写解析逻辑
// 5spinOnce（）
int main(int argc,char *argv[]){
    // 2编码 初始化 nodehandle
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tfs_sub");
    ros::NodeHandle nh;
    // 3创建订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    //A创建发布对象
    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);
    // 4编写解析逻辑

    ros::Rate rate(10);
    while(ros::ok()){
        //核心
        try
        {
            // 1计算son1与son2的相对关系
            // A相对于B的坐标系关系
            // 参数1 目标坐标系 B
            // 参数2 源坐标系 A
            // 参数3 ros：：Time（0）取时间间隔最短的两个坐标关系帧计算相对关系
            // 返回值 geometry_msgs::TransformStamped 源相对于目标坐标系的相对关系
            geometry_msgs::TransformStamped Son1ToSon2=buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
            // ROS_INFO("son1相对于son2的信息:父极:%s,子级：%s 偏移量：（%.2f,%.2f,%.2f)",
            //         Son1ToSon2.header.frame_id.c_str(),//turtle2
            //         Son1ToSon2.header.frame_id.c_str(),//turtle1
            //         Son1ToSon2.transform.translation.x,
            //         Son1ToSon2.transform.translation.y,
            //         Son1ToSon2.transform.translation.z 
            //         );

            //B根据相对坐标计算并组织速度消息
            geometry_msgs::Twist twist;
            //组织速度，只需要设置线速度的x与角速度的z
            //x=系数*开方(y^2+x^2)
            //z=系数*反正切（对边,邻边）
            twist.linear.x=0.5*sqrt(pow(Son1ToSon2.transform.translation.x,2)+pow(Son1ToSon2.transform.translation.y,2));
            twist.angular.z=4*atan2(Son1ToSon2.transform.translation.y,Son1ToSon2.transform.translation.x);
            //C发布
            pub.publish(twist);
            
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示：%s",e.what());
        }
        
    }
    // 5spinOnce（）
    return 0;
}