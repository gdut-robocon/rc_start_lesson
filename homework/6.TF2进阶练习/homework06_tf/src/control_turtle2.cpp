#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

/* 
       需求1: 换算出 turtle1 相对于 turtle2 的关系
       需求2: 计算角速度和线速度并发布
 */

int main(int argc, char *argv[])
{
    //解决中文乱码  初始化  NodeHandle
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"follow");
    ros::NodeHandle nh;
    //创建buffer缓存,创建将订阅的数据传入buffer缓存
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener lister(buffer);

    //编码解析逻辑
    //创建发布对象
    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",10);
    ros::Rate rate(10);
    while(ros::ok()){
  
  try
  {
  //计算两乌龟的相对关系
  geometry_msgs::TransformStamped T1toT2=buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
    //根据相对位置计算并组织速度消息
    geometry_msgs::Twist twist;
    //z = 系数 * 反正切(对边,邻边)
    twist.angular.z=4 * atan2(T1toT2.transform.translation.y,T1toT2.transform.translation.x);
    // x = 系数 * 开方(y^2 + x^2)
    twist.linear.x=0.5*sqrt(pow(T1toT2.transform.translation.x,2)+pow(T1toT2.transform.translation.y,2));
         //C.发布
         pub.publish(twist);
  }
  catch(const std::exception& e)
  {
   ROS_INFO("错误提示: %s",e.what());
  }
  
        rate.sleep();
        ros::spinOnce();

    }
    
    
    return 0;
}

