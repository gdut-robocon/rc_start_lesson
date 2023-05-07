# include "ros/ros.h"
# include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"yaml_publisher");
    ros::NodeHandle nh;
    nh.setParam("my_param","hello!");
    std_msgs::String my_param;
    bool result = nh.getParam("my_param",my_param.data);
    if(result) {
        ROS_INFO("%s",my_param.data.c_str());
        }
    else {
        ROS_INFO("Fair to get param 'my_param'");
        };
    ros::Publisher yaml_publisher = nh.advertise< std_msgs::String>("my_param", 10);
    while(ros::ok()){
        yaml_publisher.publish(my_param);
    }
    return 0;
}
