#include<ros/ros.h>
#include<turtlesim/Pose.h>
#include<tf2_ros/transform_broadcaster.h>
#include<geometry_msgs/TransformStamped.h>
#include<tf2/LinearMath/Quaternion.h>

std::string turtle_name;
void callback(const turtlesim::Pose::ConstPtr& pose)
{
    //获取位姿信息，转换成坐标系相对关系(核心)，并发布
    //a.创建发布对象；
    static tf2_ros::TransformBroadcaster pub;
    //b.组织被发布的消息；
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id="world";
    ts.header.stamp=ros::Time::now();
    ts.child_frame_id=turtle_name;//千万不能加引号！引号则输入字符串了 不加引号表示字符串变量
    //偏移量设置
    ts.transform.translation.x=pose->x;
    ts.transform.translation.y=pose->y;
    ts.transform.translation.z=0;
    //四元数设置(没有四元数，只有偏航角度，乌龟是2D的，无翻滚与俯仰角和翻滚角，欧拉角 0 0 theta)
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x=qtn.getX();
    ts.transform.rotation.y=qtn.getY();
    ts.transform.rotation.z=qtn.getZ();
    ts.transform.rotation.w=qtn.getW();
    //c.发布。
    pub.sendTransform(ts);

}
int main(int argc, char  *argv[])
{
//       2.设置编码问题、初始化、NodeHandle;
      setlocale(LC_ALL,"");
      ros::init(argc,argv,"dynamic_pub");
      if(argc!=2)
      {
        ROS_ERROR("请传入一个参数！");
        return 1;
      }else 
      {
            turtle_name=argv[1];
      }
      ros::NodeHandle nh;
//       3.创建订阅对象，订阅/turtle1/pose;
      ros::Subscriber sub=nh.subscribe(turtle_name+"/pose",100,callback);
//       4.回调函数处理订阅的消息：将位姿信息转化成坐标相对关系并发布(关注)；
//       5.spin();
      ros::spin();
    return 0;
}