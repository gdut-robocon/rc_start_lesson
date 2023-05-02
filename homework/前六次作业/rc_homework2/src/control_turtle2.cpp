#include "ros/ros.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tfs_sub");
    ros::NodeHandle nh;
    //创建订阅对象
    tf2_ros::Buffer buffer;//创建缓存对象
    tf2_ros::TransformListener listener(buffer);

    //创建发布对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",10);

    //编写解析逻辑
    ros::Rate rate(10);
    //1.计算son1和son2的相关系
            /*
                A相对于B的坐标系关系
                参数1.目标坐标系 B
                参数2.源坐标系 A
                参数3.ros::Time(0), 取间隔最短的两个坐标系关系帧计算相对关系
                返回值.geometry_msgs::TransformStamped 源相对于目标坐标系的相对>关系
            */
    while (ros::ok())
    {
        try
        {
            geometry_msgs::TransformStamped turtle1Toturtle2 = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
            ROS_INFO("turtle1相对于turtle2的信息 :父级:%s, 子级:%s, 相对偏移量:(%.2f,%.2f,%.2f)",
                    turtle1Toturtle2.header.frame_id.c_str(),
                    turtle1Toturtle2.child_frame_id.c_str(),
                    turtle1Toturtle2.transform.translation.x,
                    turtle1Toturtle2.transform.translation.y,
                    turtle1Toturtle2.transform.translation.z);
                        
            //根据相对关系计算并组织速度消息
            geometry_msgs::Twist twist;
            /*组织速度，只需线速度的x；与角速度的z
            x = 系数*两点间的距离
            z = 系数*反真切(对边，邻边)
            */
            twist.linear.x = 0.5 * sqrt(pow(turtle1Toturtle2.transform.translation.x,2)+pow(turtle1Toturtle2.transform.translation.y,2));
            twist.angular.z = 4 * atan2(turtle1Toturtle2.transform.translation.y,turtle1Toturtle2.transform.translation.x);
        
            //发布
            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            ROS_INFO("错误提示:%s",e.what());
        }
        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
