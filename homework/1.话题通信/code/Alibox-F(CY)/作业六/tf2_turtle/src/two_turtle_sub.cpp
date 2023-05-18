#include"ros/ros.h"
#include"tf2_ros/buffer.h"
#include"tf2_ros/transform_listener.h"
#include"geometry_msgs/TransformStamped.h"
#include"geometry_msgs/Twist.h"
#include"geometry_msgs/PointStamped.h"




int main(int argc, char  *argv[])
{   setlocale(LC_ALL,"");
    ros::init(argc,argv,"cmd_second_turtle");
    ros::NodeHandle nh;

    //创建订阅对象(#include"tf2_ros/buffer.h")/
    //(#include"tf2_ros/transform_listener.h")
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    ros::Rate r(100);
    //创建发布对象(#include"geometry_msgs/Twist.h")
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",1000);
    //组织速度消息设置线速度的x以及角速度的z（只能向前和转弯）
   while (ros::ok()) 
    {
        try
        {
            //计算turtle1turtle2之间关系（#include"geometry_msgs/TransformStamped.h"）
            geometry_msgs::TransformStamped tu1Totu2 = buffer.lookupTransform("turtle2","turtle1",ros::Time(0.0));
            geometry_msgs::Twist twist;
            twist.angular.z = 10 * atan2(tu1Totu2.transform.translation.y,tu1Totu2.transform.translation.x);
            twist.linear.x = 0.5 * sqrt(pow(tu1Totu2.transform.translation.x,2) + pow(tu1Totu2.transform.translation.y,2));

            //发布速度信息
            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
           ROS_INFO("出现异常：%s",e.what());
        }

        r.sleep();
        ros::spinOnce();
        
    }
    


    
    
    return 0;
}
