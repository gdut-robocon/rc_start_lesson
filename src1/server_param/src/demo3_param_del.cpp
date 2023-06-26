#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"param_del");
    ros::NodeHandle nh;

    //ros::NodeHandle
    //  deleteParam("键")
    //  根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false
    bool flag = nh.deleteParam("type");
    if(flag)
    {
        ROS_INFO("deleted!");
    }
    else
    {
        ROS_INFO("nothing to delete");
    }
    
    return 0;
}
