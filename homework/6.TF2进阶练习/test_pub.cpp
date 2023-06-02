#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"//动态坐标关系
#include "geometry_msgs/TransformStamped.h"//时间戳
#include "tf2/LinearMath/Quaternion.h"//欧拉角

//声明变量接受传递的参数
std::string turtle_name;

void dopose(const turtlesim::Pose::ConstPtr& pose){
    //获取位姿信息转换成坐标系相对关系（核心）并发布
    //创建发布对象
    static tf2_ros::TransformBroadcaster pub;
    //组织被发布的数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    //动态传入参数
    ts.child_frame_id = turtle_name;
    //坐标系偏移量
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;
    //四元数
    /*
        位姿信息中没有四元数，但是有一个偏航角度，又已知乌龟是2D的，无翻滚与俯仰角度，所以可以得出
        乌龟的欧拉角：0 0 theta
    */
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    //发布
    pub.sendTransform(ts);
}
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"danamic_pub");
    /*
        解析 launch 文件通过 argc 传入的参数
    */
   if(argc != 2)
   {
    ROS_INFO("传入参数不足");
    return 1;
   }
   else{
        turtle_name =argv[1];
   }
    ros::NodeHandle nh;
    //订阅的话题名称
    ros::Subscriber sub = nh.subscribe(turtle_name+"/pose",100,dopose);
    ros::spin();
    return 0;
}
