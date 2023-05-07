#include "ros/ros.h"
#include "std_msgs/String.h" //有消息传输就要包含此头文件

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");  //中文转换

    ros::init(argc,argv,"Start");  

    ros::NodeHandle nhh;  //先把节点句柄理解为下一层命名空间，可能是因为部分功能被封装了，需要声明下

    ros::Publisher pub = nhh.advertise<std_msgs::String>("input_topic",10); 
    
    std_msgs::String msg;     //要发布数据就要定义一个消息类型变量

    ros::Rate rate(5);
    
    ros::Duration(3).sleep();  //传输数据类型都一样，可有可无

    msg.data = "fighting";  //可理解为消息类型变量下有个data分支

    ROS_INFO("发布的小写字母是：%s",msg.data.c_str());  //函数的性质就是要让其转换成C风格的字符串类型

    while(ros::ok())   //一定要用到循环，不断发送消息出去！！！否则只发一次，另一边根本接受不到
    {
    pub.publish(msg);  //发布时括号里只用消息变量就行了

    rate.sleep();
        
    ros::spinOnce();  //放在while循环里想当于spin，不过这里只发布数据，可有可无
    }
    
    return 0;
}