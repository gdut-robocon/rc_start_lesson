#include<ros/ros.h>
#include<serial/serial.h>
#include<std_msgs/String.h>

#include<iostream>
#include<string>
#include<sstream>

using namespace std;


/****************************************************************************************
本文件可以向串口发送数据，需要安装serial功能包，使用sudo chmod 777 /dev/+串口名称获取串口权限
****************************************************************************************/
int serial_write(serial::Serial &ser, std::string &serial_msg)
{
    ser.write(serial_msg);
    return 0;
}

int serial_read(serial::Serial &ser, std::string &result)
{
    result = ser.read( ser.available() );
    return 0;
}


int main(int argc, char** argv)
{
    ros::init(argc, argv,"my_serial_port");
    ros::NodeHandle n;

    //创建一个serial类
   serial::Serial ser;

    //初始化串口相关设置
   ser.setPort("/dev/ttyACM0");         //设置打开的串口名称
   ser.setBaudrate(115200);                //设置串口的波特率
   serial::Timeout to = serial::Timeout::simpleTimeout(1000);           //创建timeout
   ser.setTimeout(to);                           //设置串口的timeout
 //打开串口
    
 ser.open();  
	
	//data 为发送数据
    //result 为接收数据
  	std::string data, result;
    int func(0);
    struct Robot {
 int id;
 float velocity;

 Robot(int _id, float _velocity) {
 id= _id;
 velocity = _velocity;
 }
 ~Robot(){}
 };
 Robot car(5, 3.6);

ros::Rate r(1);
    while( ros::ok() )
    {
     	data="id vrlocity\r\n";

        //串口写数据
        serial_write(ser, data);
        cout << " the data write to serial is :  " << data.c_str();
        //串口读数据
        serial_read(ser, result);
        cout << " the data read from serial is : " << result.c_str();
        cout << endl;
       r.sleep();
       ros::spinOnce();
    }

	ser.close();
    return 0;
}
