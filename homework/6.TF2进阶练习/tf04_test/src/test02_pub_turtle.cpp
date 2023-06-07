#include"ros/ros.h"
#include"turtlesim/Pose.h"
#include"tf2_ros/transform_broadcaster.h"
#include"geometry_msgs/TransformStamped.h"
#include"tf2/LinearMath/Quaternion.h"

// 发布方：需要订阅乌龟的位姿信息
// 准备：
//     话题：/turtle1/pose
//     消息：/turtlesim/pose
// 流程：
//     1包含头文件
//     2设置编码 初始化 NodeHandle
//     3创建订阅对象，订阅/turtle1/pose
//     4回调函数处理订阅的消息：将位姿信息转换成坐标相对关系并发布（关注）
//     5spin（）

//声明变量接受传递的参数
std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr& pose){
    
    //获取位姿信息，转换成坐标系相对关系（核心）并发布
    //a创建发布对象
    static tf2_ros::TransformBroadcaster pub;
    //b组织被发布的数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id="world";
    ts.header.stamp=ros::Time::now();
    ////关键点2：动态传入
    // ts.child_frame_id="turtle1";
    ts.child_frame_id=turtle_name;
    //坐标偏移量设置
    ts.transform.translation.x=pose->x;
    ts.transform.translation.y=pose->y;    
    ts.transform.translation.z=0;
    //坐标系四元数
    // 位姿信息中没有四元数，但是有个偏航角度，又已知乌龟是2D，没有翻滚和俯仰角度，所以可以得出乌龟的欧拉角
    // 0 0 theta    
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);

    ts.transform.rotation.x=qtn.getX();
    ts.transform.rotation.y=qtn.getY();
    ts.transform.rotation.z=qtn.getZ();
    ts.transform.rotation.w=qtn.getW();

    //c发布
    pub.sendTransform(ts);
}
int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;
    ////解析launch文件通过args传入的参数
    if(argc!=2){
        ROS_ERROR("请传入一个参数");
        return 1;
    }else{
        turtle_name=argv[1];


    }
    // 2设置编码 初始化 NodeHandle
    
    // 3创建订阅对象，订阅/turtle1/pose
    ////关键点1：订阅的话题名称 turtle1或turtle2得是动态传入的
    // ros::Subscriber sub=nh.subscribe("/turtle1/pose",100,doPose);
    ros::Subscriber sub=nh.subscribe(turtle_name+"/pose",100,doPose);
    // 4回调函数处理订阅的消息：将位姿信息转换成坐标相对关系并发布（关注）

    // 5spin（）
    ros::spin();
    return 0;
}