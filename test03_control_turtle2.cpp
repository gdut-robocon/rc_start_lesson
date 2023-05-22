#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/Twist.h"

/*
   进行坐标间的相对变换并获取位姿信息
   利用信息编写速度角度信息
   发布 
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",100);
    ros::Duration(2).sleep();
    ros::Rate rate(10);
    while(ros::ok()){
        geometry_msgs::TransformStamped ps_son2;
        ps_son2 = buffer.lookupTransform("turtle1","turtle2",ros::Time(0));   //返回turtle2相对于turtle1的坐标 
       
        geometry_msgs::Twist twist;
        twist.linear.x=0.5*sqrt(pow(ps_son2.transform.translation.x,2)+pow(ps_son2.transform.translation.y,2));
        twist.angular.z=4*atan2(ps_son2.transform.translation.y,ps_son2.transform.translation.x);
        pub.publish(twist);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
