#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/*
   发布方:需要订阅乌龟的位姿信息,转换成相对于窗体的坐标关系,并发布
   准备:
      话题:   /turtle1/pose
      消息:   turtlesim/Pose

       流程:
       1.包含头文件
       2.设置编码,初始化,NodeHandle;
       3.创建订阅对象,订阅  /turtle1/pose
       4.回调函数处理订阅的消息:将位姿信息转换成坐标相对关系并发布(关注)
       5.spin()
 */
 //声明变量传入参数
static std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr& pose) {
    //获取位姿信息,转换成相对关系,并发布
    //创建发布对象
    static tf2_ros::TransformBroadcaster pub;
    //组织被发布的消息
    geometry_msgs::TransformStamped ts;
    ts.child_frame_id = turtle_name;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    //坐标系偏移量  乌龟相对于世界的坐标
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;  //平面坐标系无z轴
    //坐标系四元数
         /*
            位姿信息中没有四元数,但是有个偏航角度,又已知乌龟是2D,没有翻滚和俯仰角度,所以可以得出乌龟
            的欧拉角: 0 0 theta
          */
          //将欧拉角转换为四元数
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    //设置四元数
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    //发布
    pub.sendTransform(ts);
}

int main(int argc, char* argv[])
{
    //设置编码,初始化,NodeHandle
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "dynamic_pub");
    ros::NodeHandle nh;
    // 通过传参命名
    if (argc != 2) {
        ROS_ERROR("请传入一个参数!");
        return 1;
    }
    else {
        turtle_name = argv[1];
    }
    //创建订阅对象,订阅话题名称从参数传来
    ros::Subscriber sub = nh.subscribe(turtle_name + "/pose", 100, doPose);
    //回调函数
    ros::spin();
    return 0;
}
