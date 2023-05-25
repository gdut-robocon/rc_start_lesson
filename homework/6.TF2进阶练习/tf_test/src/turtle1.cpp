#include "ros/ros.h"
#include "turtlesim/Spawn.h"
#include "geometry_msgs/Twist.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf_test/TF_ts.h"

bool doTF(tf_test::TF_ts::Request &request, tf_test::TF_ts::Response &response);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "move_turtle1");

    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    geometry_msgs::PointStamped ps;
    geometry_msgs::PointStamped ps_out;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",100);
    
    ros::Rate rate(10);
    while (ros::ok())
    {

        try
        {
            geometry_msgs::TransformStamped turtle1Toturtle2 = buffer.lookupTransform("turtle1","turtle2",ros::Time(0));
            geometry_msgs::Twist twist;
            twist.linear.x = 0.5 * sqrt(pow(turtle1Toturtle2.transform.translation.x,2) + pow(turtle1Toturtle2.transform.translation.y,2));
            twist.angular.z = 5 * atan2(turtle1Toturtle2.transform.translation.y,turtle1Toturtle2.transform.translation.x);
            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示：%s",e.what());
        }

        

        rate.sleep();
        ros::spinOnce();
    }
    
    //对齐移动
    

    //创建服务
    ros::ServiceServer server = nh.advertiseService("turtle1_ts", doTF);
    ros::spin();



    return 0;
}



bool doTF(tf_test::TF_ts::Request &request, tf_test::TF_ts::Response &response)
{   
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    geometry_msgs::PointStamped ps;
    geometry_msgs::PointStamped ps_out;
    ps.header.frame_id = "world";
    ps.header.stamp = ros::Time(0.0); // 时间戳置零，可以跳过时间戳比对，避免报错

    ps.point.x = request.arg_x;
    ps.point.y = request.arg_y;
    ps.point.z = 0.0;

    try
    {
        ps_out = buffer.transform(ps, "turtle1");
        response.ts_x = ps_out.point.x;
        response.ts_y = ps_out.point.y;
    }
    catch (const std::exception &e)
    {
        ROS_INFO("异常消息：%s", e.what());
    }

    return true;
}