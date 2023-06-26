#include "ros/ros.h"
#include "Pub_Rec/person.h"

void doPerson(const Pub_Rec::person::ConstPtr& person)
{
    ROS_INFO("我接受到的是：%s,%d,%.2f",person->name.c_str(),person->age,person->height);
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"subscriber_person");
    ros::NodeHandle nh;
    ros::Subscriber sub_person = nh.subscribe("topic_person",10,doPerson);
    ros::spin();
    return 0;
}
