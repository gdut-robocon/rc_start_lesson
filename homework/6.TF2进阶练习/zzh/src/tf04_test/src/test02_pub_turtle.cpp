#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr& pose){
    //把位姿信息转换成坐标信息
    static tf2_ros::TransformBroadcaster pub;
    //组织被发布的数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = turtle_name;
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;

    tf2::Quaternion qtn;    
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    pub.sendTransform(ts);
}



int main(int argc, char *argv[])
{
    if (argc != 4){
        ROS_ERROR("Wrong,%d",argc);
        return 1;
    } else{
        turtle_name = argv[1];
    }
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe(turtle_name+ "/pose",100,doPose);
    ros::spin();
    return 0;
}
