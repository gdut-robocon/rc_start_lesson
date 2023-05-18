#include"ros/ros.h"
#include"tf2_ros/transform_broadcaster.h"
#include"turtlesim/Pose.h"
#include"geometry_msgs/PointStamped.h"
#include"tf2/LinearMath/Quaternion.h"


//声明变量传入的参数（扩大作用域/全局？）
std::string turtle_name;

void pubPose(const turtlesim::Pose::ConstPtr &pose)
{   setlocale(LC_ALL,"");
    //获取位姿消息
    //创建tf对象（#include"tf2_ros/transform_broadcaster.h"）
    static tf2_ros::TransformBroadcaster two;
    //组织数据（#include"geometry_msgs/PointStamped.h"）
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id="world";
    ts.header.stamp = ros::Time::now();
    //动态传入子坐标系名
    ts.child_frame_id = turtle_name;
    //坐标偏移量获取yaw
    ts.transform.translation.x =pose->x;
    ts.transform.translation.y =pose->y;
    ts.transform.translation.z =0.0;
    //四元数（#include"tf2/LinearMath/Quaternion.h"）
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    
    two.sendTransform(ts);
}

int main(int argc, char *argv[])
{   
    ros::init(argc,argv,"broadcast_two_turtle");
    ros::NodeHandle nh;
    // 订阅的话题名称动态传入 (#include"turtlesim/Pose.h")
     //解析launch文件传入的参数
    turtle_name = argv[1];
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>(turtle_name+"/pose",1000,pubPose);\
    ROS_INFO("发布位置成功");
    ros::spin();
    return 0;
}
