/*
    1.头文件
    2.初始化
    3创建句柄
    4创建Publisher
    5；编写逻辑


*/
#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"
#include "std_msgs/String.h"
#include "string"
#include <sstream>

static ros::Publisher pub_1;

void doPersonMsg(const plumbing_pub_sub::Person::ConstPtr person){
    std_msgs::String Caps_msg;
    std::string original_str = person->nian;
    std::transform(original_str.begin(), original_str.end(), original_str.begin(), ::toupper);
    ROS_INFO("订阅的人信息:%s, %s, %d%s", person->name.c_str(), person->dearAi.c_str(), person->year,person->nian.c_str());
    Caps_msg.data = original_str;
    ros::NodeHandle ad_nh;
    pub_1 = ad_nh.advertise<std_msgs::String>("output_topic", 10);
    
    plumbing_pub_sub::Person person2;
    person2.name="快去看我推的孩子";
    person2.dearAi="单推星野爱";
    person2.year=1;
    person2.nian=original_str;


    pub_1.publish(person2);
    ros::Rate r(1);
    r.sleep();

    ROS_INFO("我听见:%s",Caps_msg.data.c_str());
}
int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");
    ROS_INFO("订阅者");
    ros::init(argc,argv,"Person_listener");
    ros::NodeHandle nh;
    ros::Subscriber sub=nh.subscribe<plumbing_pub_sub::Person>("input_topic",10,doPersonMsg);
    //被发布的数据
    ros::spin(); 
    return 0;
}
