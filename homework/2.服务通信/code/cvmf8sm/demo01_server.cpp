#include"ros/ros.h"
#include"plumbing_server_client/Addints.h"

bool doNums(plumbing_server_client::Addints::Request &request,
            plumbing_server_client::Addints::Response &response){
    int a = request.a;
    int b = request.b;
    ROS_INFO("request data received:num1=%d,num2=%d",a,b);
    int sum=a+b;
    response.sum=sum;
    ROS_INFO("summation result:sum=%d",sum);

    return true;
}
int main(int argc,char *argv[]){
    ros::init(argc,argv,"heishui");
    ros::NodeHandle nh;
    ros::ServiceServer server=nh.advertiseService("add_two_ints",doNums);
    ros::spin();

    
    return 0;

}