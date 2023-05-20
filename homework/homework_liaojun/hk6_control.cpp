//1.包含头文件
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ros 节点
    ros::init(argc,argv,"sub_TF");
    // 3.创建 ros 句柄
    ros::NodeHandle nh;
    // 4.创建 TF 订阅对象
    tf2_ros::Buffer buffer;
    //（生成buffer存储 处理对象）
    tf2_ros::TransformListener listener(buffer);//buffer读取器
    // 5.处理订阅到的 TF

    // 需要创建发布 /turtle2/cmd_vel 的 publisher 对象

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",1000);
    //引用发布函数 句柄API  名字=nh.advertise<泛型？>（"话题",队列长度）  

    ros::Rate rate(10);
    while (ros::ok())
    {
        try
        {
            //5-1.先获取 turtle1 相对 turtle2 的坐标信息
            geometry_msgs::TransformStamped tfs = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
            //调用转换函数
            //5-2.根据坐标信息生成速度信息 -- geometry_msgs/Twist.h
            geometry_msgs::Twist twist;
            twist.linear.x = 0.8 * sqrt(pow(tfs.transform.translation.x,2) + pow(tfs.transform.translation.y,2));
            //线速度 乌龟只有前后的线速度：x
            //利用数学关系 数学计算函数
            twist.angular.z = 5 * atan2(tfs.transform.translation.y,tfs.transform.translation.x);
            //角速度 乌龟只有转向的线速度:z
            //5-3.发布速度信息 -- 需要提前创建 publish 对象
            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("错误提示:%s",e.what());
        }
        rate.sleep();
        // 6.spin
        ros::spinOnce();
    }

    return 0;
}