 #include "ros/ros.h"
 #include "serve/AddTwoInts.h"

 bool doNums(serve::AddTwoInts::Request &request,
             serve::AddTwoInts::Response &response){
     int a = request.num1;
     int b = request.num2;
     ROS_INFO("输入的数据是 num1 = %d, num2 = %d",a,b);

     int sum = a + b;
     response.sum=sum;
     ROS_INFO("求和的结果是 sum = %d",sum);
     return true;
 }

 int main(int argc, char *argv[])
 {
     setlocale(LC_ALL,"");
     ros::init(argc,argv,"a");
     ros::NodeHandle nh;
     ros::ServiceServer server = nh.advertiseService("add_two_ints",doNums);
     ROS_INFO("服务通信启动");
     ros::spin();
     return 0;
 }
