#include "ros/ros.h"

/*
    演示参数查询
    实现：
        ros::Nodehandle-------------------------------
            getParamNames(std::vector<std::string>)
                获取所有的键,并存储在参数 vector 中 

*/


int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    //初始化ROS节点
    ros::init(argc,argv,"yaml_subscriber");
    //创建节点句柄
    ros::NodeHandle nh;
    //getParamCached(与getParam类似，只是性能上有提升，一般测试下看不出来)
    std::string yaml_param;
    bool result = nh.getParamCached("yaml_param",yaml_param);
    if(result)
    {
        ROS_INFO("接收到的信息是： %s",yaml_param);
    }else{
        ROS_INFO("被查询的变量不存在");
    }
     
    return 0;

}