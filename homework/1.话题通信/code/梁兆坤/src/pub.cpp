#include "ros/ros.h"
#include "std_msgs/String.h"
#include "stdio.h"
#include "iostream"
using namespace std;

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "converter");
    ros::NodeHandle nh;
    std_msgs::String msg;
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic", 10);
    // ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter",10,);

    setlocale(LC_ALL, "");

    // char a[10];
    // //msg.data="asd";
    // for(int i=0;i<10;i++){
    // scanf("%c",&a[i]);//ÊäÈëÊ®¸ö×Ö·û
    // msg.data+=a[i]-32;
    //                   }          
    // ros::Rate(1);
    // while(ros::ok()){
    // pub.publish(msg);


    // }
    cout << "asd" << endl;

    return 0;
}