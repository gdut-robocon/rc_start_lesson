#include "ros/ros.h"
#include "turtlesim/Pose.h"                         //获取乌龟位姿所需头文件
#include "tf2_ros/transform_broadcaster.h"          //动态坐标发布所需头文件
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/*

    已知相对于乌龟自身这个坐标系的坐标，求其对父级坐标系的坐标
    子级坐标系：乌龟自身
    父级坐标系：乌龟窗口以左下角为原点的坐标系

*/

void doPose(const turtlesim::Pose::ConstPtr& pose)
{

    static tf2_ros::TransformBroadcaster pub;         //创建广播器对象(static 是为了避免每次回调都创建新的广播器对象)
    //组织发布数据
    geometry_msgs::TransformStamped tfs;
    tfs.header.frame_id = "world";                    //父级坐标系为 world 世界坐标系，即乌龟窗口以左下角为原点的坐标系
    tfs.header.stamp = ros::Time::now();
    tfs.child_frame_id = "turtle1";                   //子级坐标系

    tfs.transform.translation.x = pose->x;            //获取乌龟位姿的x，y信息
    tfs.transform.translation.y = pose->y;
    tfs.transform.translation.z = 0;                  //乌龟为平面，故 z 为零

    //四元数的转换（俯仰x、翻滚y均为零，偏航z为乌龟位姿的theta）
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();

    pub.sendTransform(tfs);
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;

    //创建订阅者对象，订阅乌龟位姿
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);
    ros::spin();
    return 0;
}
