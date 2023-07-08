#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tfs_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    geometry_msgs::PointStamped psAtSon1;
    psAtSon1.header.stamp = ros::Time::now();
    psAtSon1.header.frame_id = "son1";
    psAtSon1.point.x = 1.0;
    psAtSon1.point.y = 2.0;
    psAtSon1.point.z = 3.0;
    ros::Rate r(10);
    while (ros::ok())
    {
        //核心
        try
        {
            //计算son1和son2的相对关系
            geometry_msgs::TransformStamped son1ToSon2 = buffer.lookupTransform("son2","son1",ros::Time(0));
            ROS_INFO("son1相对与son2的信息:父级:%s 子级:%s",son1ToSon2.header.frame_id.c_str(),son1ToSon2.child_frame_id.c_str());
            //计算son1中某个点在son2中的坐标值
            geometry_msgs::PointStamped psAtSon2 = buffer.transform(psAtSon1,"son2");
            ROS_INFO("该点在son2中的坐标值:(%.2f,%.2f,%.2f)",
                    psAtSon2.point.x,
                    psAtSon2.point.y,
                    psAtSon2.point.z
                    );
        }
        catch(const std::exception& e)
        {
            ROS_ERROR("错误提示：%s",e.what());
        }
        

        r.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
