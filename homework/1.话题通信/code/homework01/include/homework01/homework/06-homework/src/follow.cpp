#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "follow_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener zwt(buffer);

    ros::Publisher twist = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);

    ros::Rate r(10);
    while(ros::ok())
    {
        try
        {
            geometry_msgs::TransformStamped son1toson2;
            son1toson2 = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));

            geometry_msgs::Twist tmsg;
            tmsg.linear.x = 0.5 * sqrt(pow(son1toson2.transform.translation.x , 2) + pow(son1toson2.transform.translation.y , 2));
            tmsg.angular.z = 4 * atan2(son1toson2.transform.translation.y , son1toson2.transform.translation.x);

            twist.publish(tmsg);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示：%s",e.what());
        }
        r.sleep();
        ros::spinOnce();        
    }
    
    return 0;
}
