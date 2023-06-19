#include "ros/ros.h"
#include "serverclient/AddInts.h"
bool doNums(serverclient::AddInts::Request &request,
            serverclient::AddInts::Response &response){
    long aaa = request.aaa;
    long bbb = request.bbb;
    ROS_INFO("收到的请求数据:num1 = %d, num2 = %d",aaa,bbb);
    long sum = aaa + bbb;
    response.sum = sum;
    ROS_INFO("求和结果:sum = %d",sum);
    return true;
}
int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"fuwu");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("add_two_ints",doNums);
    ROS_INFO("服务器端启动");
    ros::spin();
    return 0;
}