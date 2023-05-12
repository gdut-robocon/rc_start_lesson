# 常用API详解[]()

## 1.ros::init()

**void ros::init(int &argc, char **argv, const std::string &name,uint32_t options =0U)**

**参数:**  
```
argc  - 保存传入的实参个数
argv  - 保存传入的实参（以字符串数组形式）
name  – 节点命名，不重复
options – 节点启动项，被封装进了ros::init_options，可以使一个节点多次启动
```


## 2.ros::Publisher  xxx= nh.advertise<数据类型>（）

**Publisher advertise(const std::string& topic, uint32_t queue_size, bool latch = false)**

```
topic 发布消息使用的话题

queue_size 等待发送给订阅者的最大消息数量

latch (optional) 如果为 true,该话题发布的最后一条消息将被保存，并且后期当有订阅者连接时会将该消息发送给订阅者
```

**PS：latch可以高效的发布不需要返回值，长时间不变的消息，比如静态地图**

## 3.ros::spin（）/ ros::spinnce（）

无参数

调用回调函数，spin调用时不断执行callback，不执行spin后的命令；
                        spinOnce调用时执行callback，之后跳出，继续执行后续命令
**tips:1.只有执行到spin才会调用callback
	   2.在终端表现为spin会挂起，spinonce会运行一遍然后要求新命令**

## 4.时间相关API

### --1.ros::time::now()
 获取当前时刻（相对于0时区1970年1月一日00：00：00的秒数）
### --2.ros::time var(int/double)
 设置指定时刻
### --3.ros::Duration var(double)

配合var.sleep()实现休眠指定时间

**BUG：ros::time+ros::duration可以
		  ros::duration+ros::time不行
		总结：
		Duration类型加减无碍，Tℹme类型可以相减不能相加，Duration和Time类型可以加减                         但是 Time放前面**
### ---4.ros::Timer var = nh.createtimer（）

**Timer createTimer(Duration period, const TimerCallback& callback, bool oneshot = false,
bool autostart = true)

**配合回调函数viod cb  (ros::TimerEvent & callback)**
```
period 时间间隔
callback 回调函数
		oneshot 如果设置为 true则为一次性，否则循环执行。
autostart 如果为true，返回已经启动的定时器,设置为 false，需要手动启动。
```
**Tips：**
ROS_INFO("%.2f",var.Tosec(**double**))
ROS_INFO("%.d",var.sec(**int**))
**创建nh才可使用（尽管没有调用命令但实际上调用了）**

### 5. ros::shutdown()

	无参数，停止节点

# 自定义头文件

## 编写头文件

### 1.创建头文件
 在功能包/include/功能包同名文件 下创建
### 2.编写头文件
格式如下
1.先声明头文件保护
2.定义namespce/calss/run
3.结束
```
#ifndef _HELLO_H
#define _HELLO_H

namespace hello_ns{

class HelloPub {

public:
    void run();
};

}
#endif

```
## 配置头文件
### 1.添加头文件路径
1.转到控制台，pwd获取头文件路径
2.复制粘贴到cpp.json文件的includepath里面（加/**）
### 2.配置CMakelist文件
放开dictionary下的include
配置
```
include_directories(

include

${catkin_INCLUDE_DIRS}

)

## Declare a C++ library

add_library(${PROJECT_NAME}-------------------自定义名字
include/功能包名（${POJECT_NAME}）/头文件.h-------头文件
src/${PROJECT_NAME}/API.cpp-------------------源文件
)




