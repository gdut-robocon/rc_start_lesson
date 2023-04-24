#include "ros/ros.h"
#include "serverclient/AddInts.h"
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    if(argc !=3){
        ROS_INFO("提交的参数个数不对。");
        return 1;
    }
    ros::init(argc,argv,"kehu");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<serverclient::AddInts>("add_two_ints");
    serverclient::AddInts ai;
    ai.request.aaa = atoi(argv[1]);
    ai.request.bbb = atoi(argv[2]);
    client.waitForExistence();
    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("响应成功！");
        ROS_INFO("响应结果 = %d",ai.response.sum);
    } else{
        ROS_INFO("处理失败....");
    }

    return 0;
}