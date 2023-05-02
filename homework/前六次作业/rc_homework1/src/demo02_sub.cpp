#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p){
    std_msgs::String message;
    message.data = msg_p->data;
    int i = 0;
    for(i=0; message.data[i]!='\0';i++){
        if(isupper(message.data[i])){
            message.data[i] = tolower(message.data[i]);
        }else if(islower(message.data[i])){
            message.data[i] = toupper(message.data[i]);
        }else{
            continue;
        }
    }
    ROS_INFO("我听见:%s",message.data.c_str());
    static ros::NodeHandle nh;//设置为静态，避免重复创建
    static ros::Publisher pub = nh.advertise<std_msgs::String>("output_topic",10);
    pub.publish(message);
}
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"sub_c");
    //3.实例化 ROS 句柄
    ros::NodeHandle nh;

    //4.实例化 订阅者 对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("input_topic",10,doMsg);

    ros::spin();
    return 0;
}
