#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/transform_broadcaster.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"move_turtle2");
    
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);

    tf2_ros::TransformBroadcaster tf_pub;

    ros::Rate rate(10);
    while (ros::ok())
    {
        geometry_msgs::Twist twist;
        twist.linear.x = 2;

        ros::Time sand = ros::Time::now();
        srand(sand.sec);
		
        twist.angular.z = 5 * ((rand() / double(RAND_MAX)) - 0.5);

        pub.publish(twist);

        try
        {
            geometry_msgs::TransformStamped turtle1Toturtle2 = buffer.lookupTransform("turtle1","turtle2",ros::Time(0));
            tf_pub.sendTransform(turtle1Toturtle2);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示：%s",e.what());
        }

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
