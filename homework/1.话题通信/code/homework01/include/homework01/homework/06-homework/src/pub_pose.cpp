#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

std::string turtle_name; //全局变量，两个函数都要用

void poseget (const turtlesim::Pose::ConstPtr& posemsg)
{
    static tf2_ros::TransformBroadcaster zwt;
   
    geometry_msgs::TransformStamped posemsg2;

    posemsg2.header.stamp = ros::Time::now();
    posemsg2.header.frame_id = "zwt_world";
    posemsg2.child_frame_id = turtle_name;

    posemsg2.transform.translation.x = posemsg->x;
    posemsg2.transform.translation.y = posemsg->y;
    posemsg2.transform.translation.z = 0;

    tf2::Quaternion four1;
    four1.setRPY(0,0,posemsg->theta);

    posemsg2.transform.rotation.x = four1.getX();
    posemsg2.transform.rotation.y = four1.getY();
    posemsg2.transform.rotation.z = four1.getZ();
    posemsg2.transform.rotation.w = four1.getW();

    zwt.sendTransform(posemsg2);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "pub_pose");
    ros::NodeHandle nh;

    if(argc != 2)
    {
        ROS_ERROR("Usage: add a param!");
        return 1;
    }else{
        turtle_name = argv[1];
    } 
    
    ros::Subscriber jdfx = nh.subscribe(turtle_name + "/pose",100,poseget);
    ros::spin();

    return 0;
}
