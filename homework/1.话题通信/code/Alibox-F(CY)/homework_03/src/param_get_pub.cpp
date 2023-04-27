#include"ros/ros.h"
#include <sstream>
#include<functional>
#include <string>
#include <iostream>
#include "std_msgs/String.h"
using namespace std;
int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_Publisher");
    
    ros::NodeHandle nh;
    

    std::string str="flase";
    std_msgs::String upper;
    
     bool result=nh.getParam("my_param",str);
     upper.data=str;
    if(result){
        ROS_INFO("获取的是：%s",upper.data.c_str());
    }else{
        ROS_INFO("查询的参数不存在");}
        
    // std::vector<std::string> names;
    // nh.getParamNames(names);
    // for (auto&&name:names)
    // {
    //    ROS_INFO("遍历的元素：%s",name.c_str());
    // }std::vector<std::string> names;
    // nh.getParamNames(names);
    // for (auto&&name:names)
    // {
    //    ROS_INFO("遍历的元素：%s",name.c_str());
    // }
   

   
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param",10);

    ros::Rate r(1);

    //节点不死
    while (ros::ok())
    {

        pub.publish(upper);
        //加入调试，打印发送的消息
        ROS_INFO("发送的消息:%s",upper.data.c_str());

        //根据前面制定的发送贫频率自动休眠 休眠时间 = 1/频率；
        r.sleep();
        ros::spinOnce();
    }

    return 0;
}
