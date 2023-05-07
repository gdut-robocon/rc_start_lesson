#include "ros/ros.h"
#include "std_msgs/String.h"
//回调函数
void doMsg(const std_msgs::String::ConstPtr &msg){
	
	std_msgs::String new_msg;
    std::string original_msg = msg->data;
    //大小写转换 
    std::transform(original_msg.begin(),original_msg.end(),original_msg.begin(),::toupper);
    new_msg.data = original_msg;
    ROS_INFO("发布的数据是：%s",new_msg.data.c_str());
    ros::NodeHandle nh2;
    ros::Publisher pub = nh2.advertise< std_msgs::String>("output_topic", 10);
    pub.publish(new_msg);

}
   
    
int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    //初始化节点 不能重名！！
    ros::init(argc,argv,"input_topic");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建订阅者对象 队列长度 自动清除超过长度的
    ros::Subscriber sub = nh.subscribe("string_converter",10,doMsg);
    //处理订阅到的数据
    ros::spin();

    return 0;
}
