#include "ros/ros.h"
#include "plumbing_server_client/addints.h"

bool doNums(plumbing_server_client::addints::Request &request,
            plumbing_server_client::AddInts::Response &response){
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到请求数据:num1 = %d, num2 = %d",num1, num2);
    int sum=num1+num2;
    response.sum=sum;
    ROS_INFO("求和结果:sum=",sum);
    return true;
    return true;
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addints",doNums);
    ros::spin();
}