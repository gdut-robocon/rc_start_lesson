#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2/LinearMath/Quaternion.h"

std::string turtle_name;

void callback(const turtlesim::Pose::ConstPtr& pose)
{
    //获取位姿信息，转化为坐标相对消息，并发布
    //创建发布对象，静态
    static tf2_ros::TransformBroadcaster pub;

    //组织发布数据
    geometry_msgs::TransformStamped tfs;
    tfs.header.frame_id="world";
    tfs.header.stamp=ros::Time::now();//时间戳
    tfs.child_frame_id = turtle_name;
    //坐标系偏移量设置
    tfs.transform.translation.x=pose->x;
    tfs.transform.translation.y=pose->y;
    tfs.transform.translation.z=0.0;//二维坐标无z

    //坐标系四元数设置
    /*
        位姿信息当中没有四元数,但有偏航角度,又已知乌龟是2D,没有翻滚与俯仰,所以>可以得出乌龟的欧拉角
        为0 0 theta
    */
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    tfs.transform.rotation.w=qtn.getW();
    tfs.transform.rotation.x=qtn.getX();
    tfs.transform.rotation.y=qtn.getY();
    tfs.transform.rotation.z=qtn.getZ();
    //发布数据
    pub.sendTransform(tfs);
}

int main(int argc, char *argv[])
{
    // 设置编码
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    if(argc!=2){
        ROS_INFO("请传入一个参数");
        return 1;
    }else{
        turtle_name = argv[1];
        ROS_INFO("乌龟 %s 坐标发送启动",turtle_name.c_str());
    }

    ros::NodeHandle nh;
    //创建订阅对象，订阅turtle1/pose(乌龟1的位姿)
    ros::Subscriber sub = nh.subscribe(turtle_name + "/pose",100,callback);//订阅话题是turtle1/pose，但由于名字为动态，故分开拼接
    ros::spin();
}
