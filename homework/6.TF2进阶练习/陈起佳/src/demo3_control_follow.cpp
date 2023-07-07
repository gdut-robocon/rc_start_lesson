//引头文件
#include "ros/ros.h"
#include "tf2_ros/buffer.h"                              //设置缓存所需头文件
#include "tf2_ros/transform_listener.h"                  //设置订阅者对象所需头文件
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"         //程序运行所需头文件（坐标转换依赖于这个头文件）
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //初始化节点、句柄、订阅节点
    ros::init(argc,argv,"dynamic_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;                             //设置缓存对象（转换后的坐标存于缓存中）
    tf2_ros::TransformListener sub(buffer);             //设置订阅者对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);
    ros::Rate rate(2);                                  //设置发布频率
    while(ros::ok())
    {
        rate.sleep();
        //try-catch 结构可以避免接收不到信息时报错
        try
        {
            geometry_msgs::TransformStamped tfs = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
            ROS_INFO("turtle2 相对于 turtle1 的偏移量为：(%.2f,%.2f)",tfs.transform.translation.x,tfs.transform.translation.y);
            geometry_msgs::Twist twist;
            twist.linear.x = 1 * sqrt(pow(tfs.transform.translation.x,2)+pow(tfs.transform.translation.y,2));
            twist.angular.z = 3 * atan2(tfs.transform.translation.y,tfs.transform.translation.x);
            pub.publish(twist);
           
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
