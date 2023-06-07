#include"ros/ros.h"
#include "ros_tutorials_service/AddTwoInts.h"


int main (int argc,char *argv[]){
if(argc!=3){
    ROS_INFO("提交的个数不对。");

    return 1;
}



setlocale(LC_ALL,"");  
ros::init(argc,argv,"拉拉");
ros::NodeHandle nh;
ros::ServiceClient client = nh.serviceClient<ros_tutorials_service_client::AddTwoInts>("add_two_ints");
ros_tutorials_service_client::AddTwoInts ai;
ai.request.num1 = atoi(argv[1]);
ai.request.num2 = atoi(argv[2]);

//client.waitForExistence();
ros::service::waitForService("AddTwoInts");

bool flag = client.call(ai);
if(flag){
    ROS_INFO("响应成功！");
    ROS_INFO("响应结果 = %d",ai.response.sum);
}else{
    ROS_INFO("处理失败......");
}

   return 0;
}
