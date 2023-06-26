#include "ros/ros.h"
#include "turtlesim/Pose.h"
/*

        1.话题名称 /turtle1/pose
        2.消息类型 turtlesim/Pose

*/

void doPos(const turtlesim::Pose::ConstPtr &pos)
{
    ROS_INFO("坐标：(%.2f,%.2f),朝向：%.2f,线速度：%.2f,角速度：%.2f",pos->x,pos->y,pos->theta,pos->linear_velocity,pos->angular_velocity);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"turtle_pos_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("turtle1/pose",100,doPos);
    ros::spin();
    return 0;
}
