//引头文件
#include "ros/ros.h"
#include "tf2_ros/buffer.h"                              //设置缓存所需头文件
#include "tf2_ros/transform_listener.h"                  //设置订阅者对象所需头文件
#include "geometry_msgs/PointStamped.h"                  //存储坐标点所需头文件
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"         //程序运行所需头文件（坐标转换依赖于这个头文件）

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化节点、句柄、订阅节点
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;                             //设置缓存对象（转换后的坐标存于缓存中）
    tf2_ros::TransformListener sub(buffer);             //设置订阅者对象
    geometry_msgs::PointStamped ladar_point;            //创建存储子级坐标系下点的变量
    
    ros::Rate rate(1);                                  //设置发布频率
    while(ros::ok())
    {
        rate.sleep();

        //设置相对于子级坐标系 ladar 的信息
        ladar_point.header.frame_id = "ladar";
        ladar_point.header.stamp = ros::Time::now();
        ladar_point.point.x = 1.0;
        ladar_point.point.y = 2.0;
        ladar_point.point.z = 7.3;
        
        //try-catch 结构可以避免接收不到信息时报错
        try
        {
            
            geometry_msgs::PointStamped base_point;                       //设置存储父级坐标系下点的信息的变量
            base_point = buffer.transform(ladar_point,"base");            //转换坐标并赋值到 base_point
            ROS_INFO("转换后的坐标为（%.2f,%.2f,%.2f),参考的坐标系为 %s",
                            base_point.point.x,
                            base_point.point.y,
                            base_point.point.z,
                            base_point.header.frame_id.c_str());
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            //ROS_INFO("未收到数据···");
            ROS_INFO("%s",e.what());
        }

        ros::spinOnce();
        
    }
    return 0;
}
