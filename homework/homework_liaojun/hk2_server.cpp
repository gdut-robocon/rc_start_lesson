#include<ros/ros.h>
#include<ros_tutorials_service/AddInts.h>

    bool callback(ros_tutorials_service::AddInts::Request &request,
                  ros_tutorials_service::AddInts::Response &response)
       {//1.处理请求
        int a=request.a;
        int b=request.b;
        ROS_INFO("收到的请求数据：a=%d,b=%d",a,b);
          //2.组织响应
        int sum=a+b;
        response.sum=sum;
        ROS_INFO("求和结果：sum=%d",sum);
        return true;
       }
int main(int argc, char *argv[])
{      setlocale(LC_ALL,"");
       // 1.包含头文件
       // 2.初始化ros节点；
       ros::init(argc,argv,"calculator");
       // 3.创建节点句柄；
       ros::NodeHandle nh;
       // 4.创建一个服务对象；
       ros::ServiceServer server=nh.advertiseService("add_two_ints",callback);
       ROS_INFO("服务器启动成功。");
       // 5.处理请求产生响应；
       // 6.spin();
       ros::spin();
    return 0;
}
