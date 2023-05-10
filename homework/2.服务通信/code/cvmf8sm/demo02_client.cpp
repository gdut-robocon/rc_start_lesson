#include"ros/ros.h"
#include"plumbing_server_client/Addints.h"
int main(int argc,char *argv[]){
    if(argc!=3){
        ROS_INFO("The number of parameters submitted is incorrect");
        return 1;
    }

    ros::init(argc,argv,"daBao");
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<plumbing_server_client::Addints>("add_two_ints");
    plumbing_server_client::Addints ai;
    ai.request.a=atoi(argv[1]);
    ai.request.b=atoi(argv[2]);
    // client.waitForExistence();   -->as same as next line
    ros::service::waitForService("addints");
    bool flag =client.call(ai);
    if(flag){
        ROS_INFO("response successful!");
        ROS_INFO("response result=%ld",ai.response.sum);
    }else{
        ROS_INFO("response fail...");
    }
    
    return 0;

}