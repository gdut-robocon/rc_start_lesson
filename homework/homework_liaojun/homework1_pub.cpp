#include<ros/ros.h>
#include<std_msgs/String.h>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;


int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");
    cout << "请输入要发布的消息（小写）:\n";
    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    ros::init(argc,argv,"input_topic");
    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<std_msgs::String>("string_converter",10);
    std_msgs::String msg;
    ros::Rate rate(1);
    int count=0;
    while(ros::ok())
    {   count++;
        std::stringstream ss;
        ss<<str<<count;
        msg.data=ss.str();
        pub.publish(msg);
        ROS_INFO("发布的数据是：%s",ss.str().c_str());
        rate.sleep();
        ros::spinOnce()
        return 0;
    }
}
