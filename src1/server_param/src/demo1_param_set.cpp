#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_set");
    ros::NodeHandle nh;
    //设置参数，即键值对
    nh.setParam("type","black");
    nh.setParam("radius",0.5);
    //修改参数
    nh.setParam("type","white");
    nh.setParam("radius",2.0);
    return 0;
}
