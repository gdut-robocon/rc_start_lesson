#include "ros/ros.h"

/*
    演示参数查询
    实现：
        ros::Nodehandle-------------------------------
            param(键,默认值) 
                存在，返回对应结果，否则返回默认值

            getParam(键,存储结果的变量)
                存在,返回 true,且将值赋值给参数2
                若果键不存在，那么返回值为 false，且不为参数2赋值

            getParamCached键,存储结果的变量)--提高变量获取效率
                存在,返回 true,且将值赋值给参数2
                若果键不存在，那么返回值为 false，且不为参数2赋值

            getParamNames(std::vector<std::string>)
                获取所有的键,并存储在参数 vector 中 

            hasParam(键)
                是否包含某个键，存在返回 true，否则返回 false

            searchParam(参数1，参数2)
                搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
        ros::param------------------------------------

*/


int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    //初始化ROS节点
    ros::init(argc,argv,"yaml_subscriber");
    //创建节点句柄
    ros::NodeHandle nh;

    /*1.param(0.5为默认值)
    double radius = nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);
    */

    //2.getParam
    //3.getParamCached(与getParam类似，只是性能上有提升，一般测试下看不出来)
    std::string yaml_param;
    bool result = nh.getParamCached("yaml_param",yaml_param);
    if(result)
    {
        ROS_INFO("接收到的信息是： %s",yaml_param);
    }else{
        ROS_INFO("被查询的变量不存在");
    }
     
    /*4.getParamNames(查询所有元素)
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names)
    {
        ROS_INFO("遍历到的元素:%s",name.c_str());
    }*/

    /*5.hasParam（判断元素是否存在）
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusx");
    ROS_INFO("radius存在吗? %d",flag1);
    ROS_INFO("radiusx存在吗? %d",flag2);
    */

    /*6.searchParam（搜索元素）
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果:%s",key.c_str());
    */

    return 0;

}