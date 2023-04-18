#include<ros/ros.h>
#include<ros_tutorials_service/AddInts.h>
/* 
客户端：提交两个整数，并响应处理的信息
        1.包含头文件
        2.初始化ros节点；
        3.创建节点句柄；
        4.创建一个客户端对象；
        5.提交请求并处理响应；
        6.spin();
实现参数动态提交：
        1.格式：rosrun xxxxxxxx12 34
        2.节点执行时，需要获取命令中的参数，并组织进request
*/
int main(int argc, char *argv[])
{       setlocale(LC_ALL,"");
        if(argc !=3){
            ROS_INFO("提交的参数个数不对");
            return 1;
        } //优化实现，获取命令中的参数
        
        ros::init(argc,argv,"palyers"); //2.初始化ros节点；
        ros::NodeHandle nh;//3.创建节点句柄；
        ros::ServiceClient client=nh.serviceClient<ros_tutorials_service::AddInts>("add_two_ints");
        //4.创建一个客户端对象；
        ros_tutorials_service::AddInts ai;
        ai.request.a=atoi(argv[1]);
        ai.request.b=atoi(argv[2]);//5.1组织请求
        bool flag= client.call(ai);//5.2处理响应  //5.提交请求并处理响应；
        if(flag)
        {
            ROS_INFO("响应成功。");
            ROS_INFO("响应结果=%d",ai.response.sum);
        }else{
            ROS_INFO("处理失败。");
        ros::spin();
        return 0;
}
