#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"twotransform_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);

    ros::Rate rate(3);
    geometry_msgs::PointStamped son1;
    geometry_msgs::TransformStamped son1Toson2;
    son1.header.frame_id = "son1";
    son1.header.stamp = ros::Time::now();
    son1.point.x = 3;
    son1.point.y = 3;
    son1.point.z = 3;

    while(ros::ok())
    {
        rate.sleep();
        try
        {
            //坐标系转换
            son1Toson2 = buffer.lookupTransform("son2","son1",ros::Time(0));
            ROS_INFO("父级坐标系:%s,子级坐标系:%s,偏移量:(%.2f,%.2f,%.2f)",
                        son1Toson2.header.frame_id.c_str(),
                        son1Toson2.child_frame_id.c_str(),
                        son1Toson2.transform.translation.x,
                        son1Toson2.transform.translation.y,
                        son1Toson2.transform.translation.z);


            //坐标点转换
            geometry_msgs::PointStamped son2;
            son2 = buffer.transform(son1,"son2");
            ROS_INFO("转换后的坐标:(%.2f,%.2f,%.2f),父级坐标系: %s",
                            son2.point.x,
                            son2.point.y,
                            son2.point.z,
                            son2.header.frame_id.c_str()
                            );
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误信息：%s",e.what());
        }
        ros::spinOnce();
        
    }
    return 0;
}
