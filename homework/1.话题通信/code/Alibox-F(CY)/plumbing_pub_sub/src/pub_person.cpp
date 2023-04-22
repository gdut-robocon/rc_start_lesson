/*
    1.头文件
    2.初始化
    3创建句柄
    4创建Publisher
    5；编写逻辑


*/
#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

int main(int argc, char *argv[])
{  
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"Person_talker");
    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<plumbing_pub_sub::Person>("input_topic",10);
    //被发布的数据
    plumbing_pub_sub::Person person;
    std::string ss="million years";
    person.name="快去看我推的孩子";
    person.dearAi="单推星野爱";
    person.year=1;
    person.nian=ss;
    //频率
    ros::Rate rate(1);
    //循环发布
    while(ros::ok){
        person.year+=1;
        pub.publish(person);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
