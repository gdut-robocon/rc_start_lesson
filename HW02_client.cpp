#include "ros/ros.h"
#include "serve/AddTwoInts.h"

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"kehu");

    ros::NodeHandle nh;
//创建一个客户端对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("AddInts");
//提交请求并处理响应
    serve::AddTwoInts ai;
//组织请求
  ai.request.a = atoi(argv[1]);
  ai.request.b = atoi(argv[2]);
//处理响应
  bool flag = client.call(ai);
  if(flag){
    ROS_INFO("响应成功");
    ROS_INFO("响应结果 = %d",ai.response.sum);
  } else{
    ROS_INFO("处理失败");
  }
    return 0;
}
