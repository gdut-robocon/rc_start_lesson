#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"

int main(int argc,char* argv[]){
    setlocale(LC_ALL,"");
    //节点 yaml_publisher
    ros::init(argc,argv,"yaml_publisher");
    ros::NodeHandle nh;
    //话题 yaml_param 队列MAX10
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param",10);
    //新建消息类型 对象
    std_msgs::String msg;
    //存变量
    std::string param;

    nh.param<std::string>("my_param",param,"找不到变量");

    msg.data = param;

    ros::Rate rate(10);
    ROS_INFO("正在发送信息");

    while(ros::ok()){
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();

    }
return 0;
}

    
