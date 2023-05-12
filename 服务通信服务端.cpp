#include"ros/ros.h"
#include "ros_tutorials_service/AddTwoInts.h"

bool doNums(plumbing_server_client::AddTwoInts::Request &request,
            plumbing_server_client::AddTwoInts::Response &response){
     int num1 = request.num1;
     int num2 = request.num2;
     ROS_INFO("收到的请求数据：num1=%d,num2=%d",num1,num2);
     int sum = num1 + num2;
     response.sum = sum;
     ROS_INFO("求和结果： sum = %d",sum);

    return true;
}

int main(int argc,char *argv[]){
setlocale(LC_ALL,"");  

ros::init(argc,argv,"思思");
ros::NodeHandle nh;
ros::ServiceServer server = nh.advertiseService("add_Two_Ints",doNums);
ROS_INFO("服务器端启动");
ros::spin();
    return 0;
}
