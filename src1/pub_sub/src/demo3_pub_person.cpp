#include "ros/ros.h"
#include "Pub_Rec/person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"publisher_person");
    ros::NodeHandle nh;
    ros::Publisher pub_person = nh.advertise<Pub_Rec::person>("topic_person",10);
    Pub_Rec::person person;
    person.name = "张三";
    person.age = 18;
    person.height = 1.78;
    ros::Rate rate(10);
    ros::Duration(2).sleep();
    while(ros::ok())
    {
        pub_person.publish(person);
        ROS_INFO("发出的信息为：%s,%d,%.2f",person.name.c_str(),person.age,person.height);
        person.age++;
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
