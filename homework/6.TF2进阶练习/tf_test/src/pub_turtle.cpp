#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/*
    发布方：需要订阅乌龟的位姿信息，转换成相对于窗体的坐标关系，并发布
    准备：
        话题：/turtle1/pose
        消息：//turtlesim/Pose

    流程：
        1.包含头文件
        2.设置编码，初始化，nh
        3.创建订阅对象，订阅/turtle1/pose
        4.回调函数处理订阅的信息
        5.spin()
*/
std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr& pose){
    static tf2_ros::TransformBroadcaster pub;//创建发布对象
    static tf2::Quaternion qtn;//四元数计算

    geometry_msgs::TransformStamped ts;//数据对象

    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = turtle_name;

    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;

    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.w = qtn.getW();
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();

    pub.sendTransform(ts);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"pose_pub");
    ros::NodeHandle nh;

    if(argc != 2){
        ROS_INFO("请传入一个参数");
        return 1;
    }else{
        turtle_name = argv[1];
    }

    ros::Subscriber sub = nh.subscribe(turtle_name + "/pose",100,doPose);

    ros::spin();
    return 0;
}