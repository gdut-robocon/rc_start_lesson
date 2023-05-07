#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/*
    fuwuduanshixian:jiexikehuduantijiaodemsg,bingqiechanshengxiangying
    1.include head file
    2.intialize node of ros
    3.create the handle
    4.create a serviced object
    5.deal with requestment and produce response
    6.spin()
*/

bool doNums(plumbing_server_client::AddInts::Request &request,
            plumbing_server_client::AddInts::Response &response){
    //1.deal with requestment
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("the recived requestment msgs:num1 = %d, num2 = %d",num1,num2);
    int sum = num1 + num2;
    ROS_INFO("the goal: sum = %d",sum);
    response.sum = sum;
    //2.organize response
    
    
    return true;
}
int main(int argc, char *argv[])
{
    
    
    // 2.intialize node of ros
    ros::init(argc,argv,"add_Two_ints");//the name of node is weiyi
    // 3.create the handle
    ros::NodeHandle nh;
    // 4.create a service object
    ros::ServiceServer server = nh.advertiseService("addTwoInts",doNums);
    // 5.deal with requestment and produce response
    // 6.spin()
    ROS_INFO("the server start");
    ros::spin();
    // return 0;
}
