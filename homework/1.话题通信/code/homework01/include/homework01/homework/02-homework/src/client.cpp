#include "ros/ros.h"
#include "ros_tutorials_service/AddTwoInts.h"

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");

    ROS_INFO("客户端需求:");

    if(argc != 3)    //程序本身算一个参数，加上两个整形，总共三个
    {
        ROS_INFO("提交的参数个数不对");
        return 1;    //返回1没看懂
    }

    ros::init(argc,argv,"client_zwt");

    ros::NodeHandle h;

    ros::ServiceClient zwt = h.serviceClient<ros_tutorials_service::AddTwoInts>("add_two_ints");  //创建一个客户对象zwt

    ros_tutorials_service::AddTwoInts need;   //定义一个消息类型变量用来传输对接响应另一个节点，类似于之前的msg，
                                                      //此变量旗下有request和response，两者旗下又有srv里的整形
                                                      //但好像服务方不需要定义这样的消息类型变量，理解为客户端自拿自取？
    need.request.a = atoi(argv[1]);
    need.request.b = atoi(argv[2]);   //转换字符串为整形

    zwt.waitForExistence();   //创建的客户对象旗下可以使用很多函数

    bool sign = zwt.call(need);   //接收响应服务端，那边返回的值只有0/1，所以用bool，sum已经被改变了，直接提取就好

    if(sign)   //返回值是1则响应成功，与那边return 1相对应
    {
        ROS_INFO("响应成功！！！");
        ROS_INFO("响应结果 = %d",need.response.sum);   //前面不转换类型的话，这里的打印会出错
    }else{
        ROS_INFO("响应失败...");
    }

    return 0;
}