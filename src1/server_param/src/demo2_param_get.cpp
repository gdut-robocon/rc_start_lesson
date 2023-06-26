#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"param_get");
    ros::NodeHandle nh;

    //param(键,默认值) 
    //      存在，返回对应结果，否则返回默认值
    double r  = nh.param("radius",9.0);
    ROS_INFO("radius is %.2f",r);

    //【getParam(键,存储结果的变量)】和【getParamCached键,存储结果的变量)--提高变量获取效率】效果一样
    //      存在,返回 true,且将值赋值给参数2
    //      若果键不存在，那么返回值为 false，且不为参数2赋值
    std::string type;
    bool flag1 = nh.getParam("type",type);
    if(flag1)
    {
        ROS_INFO("the type is %s",type.c_str());
    }
    else
    {
        ROS_INFO("no this thing");
    }

    //getParamNames(std::vector<std::string>)
    //     获取所有的键,并存储在参数 vector 中 
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("the names are: %s",name.c_str());
    }
    
    //hasParam(键)
    //      是否包含某个键，存在返回 true，否则返回 false
    bool flag2 = nh.hasParam("type");
    ROS_INFO("if there have? %d",flag2);
    bool flag3 = nh.hasParam("typexxx");
    ROS_INFO("if there have? %d",flag3);

    //searchParam(参数1，参数2)
    //      搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
    std::string type_param;
    nh.searchParam("typexxx",type_param);
    ROS_INFO("%s",type_param.c_str());

    return 0;
}
