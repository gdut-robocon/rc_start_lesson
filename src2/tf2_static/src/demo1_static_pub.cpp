
//引头文件
#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"       //广播器所需头文件
#include "geometry_msgs/TransformStamped.h"             //设置坐标系信息所需头文件
#include "tf2/LinearMath/Quaternion.h"                  //将欧拉角转换成四元数所需头文件

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    //初始化节点、句柄、广播器和坐标系对象
    ros::init(argc,argv,"static_pub");
    ros::NodeHandle nh;
    tf2_ros::StaticTransformBroadcaster pub;
    geometry_msgs::TransformStamped tfs;

    //设置坐标系头信息
    tfs.header.frame_id = "base";               //被参照的坐标系的名称（父级坐标系）
    tfs.header.stamp = ros::Time::now();        //时间
    tfs.child_frame_id = "ladar";               //参照 base 坐标系的名称（子级坐标系）

    //设置子级坐标系相对于父级坐标系的偏移（x,y,z）
    tfs.transform.translation.x = 0.2;          
    tfs.transform.translation.y = 0.0;
    tfs.transform.translation.z = 0.5;

    //设置由欧拉角变换得来的四元数
    //tfs 中的 rotation 储存的是四元数，而寻常使用的是欧拉角，故需进行变换
    tf2::Quaternion qtn;                        //创建 Quaternion 对象
    qtn.setRPY(0,0,0);                          //设置欧拉角信息
    tfs.transform.rotation.x = qtn.getX();      //将欧拉角转为四元数
    tfs.transform.rotation.y = qtn.getY();      //将欧拉角转为四元数
    tfs.transform.rotation.z = qtn.getZ();      //将欧拉角转为四元数
    tfs.transform.rotation.w = qtn.getW();      //将欧拉角转为四元数

    //广播器发送坐标系数据
    pub.sendTransform(tfs);

    //spin()
    ros::spin();

    return 0;
}
