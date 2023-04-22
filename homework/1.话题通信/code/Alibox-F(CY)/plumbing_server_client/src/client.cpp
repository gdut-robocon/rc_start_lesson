//         1.包含头文件
//         2.初始化 ROS 节点
//         3.创建 ROS 句柄
//         4.创建 服务 对象
//         5.回调函数处理请求并产生响应
//         6.由于请求有多个，需要调用 ros::spin()







#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"

int main(int argc, char *argv[])
{   
    //获取命令中的参数
    setlocale(LC_ALL,"");
    if(argc !=3){
        ROS_INFO("参数个数有误");
        return 1;
    }

    
    
     ros::init(argc,argv,"Clienter");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::Addints>("Addints");

    plumbing_server_client::Addints me;

    me.request.a=atoi(argv[1]);
    me.request.b=atoi(argv[2]);

    client.waitForExistence();

    bool flag=client.call(me);
    if(flag){
        ROS_INFO("响应成功！");

        ROS_INFO("结果=%d",me.response.sum);
    }else {
        ROS_INFO("响应失败");

    }
    return 0;
}
