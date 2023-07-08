#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;
    //创建一个buffer缓存
    //创建一个监听对象（把监听到的数据存到buffer）
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "laser";
    ps.header.stamp = ros::Time::now();
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;
    //转换算法
    ros::Rate r(10);
    // r.sleep();
    while(ros::ok()){
        //把ps转换成base_link
        geometry_msgs::PointStamped ps_out;
        try
        {
            ps_out = buffer.transform(ps,"base_link");
            ROS_INFO("转换后的坐标值：(%.2f,%.2f,%.2f),参考系：%s",
                ps_out.point.x,
                ps_out.point.y,
                ps_out.point.z,
                ps_out.header.frame_id.c_str());
        }
        catch(const std::exception& e)
        {
            ROS_ERROR("异常消息：%s",e.what());
        }
        

        r.sleep();
        ros::spinOnce();
    }
    return 0;
}
