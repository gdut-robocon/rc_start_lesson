# ROS通信机制の进阶

># Api
>api是一些预先被定义的函数，可以在基于软件或者某种硬件的时候访问例程。也就是应用程序编程接口。我们可以通过API接口或者操作命令来使用我们的操作系统。

---
### 目录
1. API
 - 节点初始化相关的API
 - NodeHandle使用有关的API
- 话题的发布方，订阅方相关的API
- 服务端客户端相关的API
- 时间相关的API
- 日志输出相关的API
2. ROS常用的头文件与源文件的使用
### 节点初始化的API
[这是roswiki的网站，里面有](wiki.ros.org/APIs)
**roscpp**
应用广泛的一个库。ros入门之后需要多看一下官方的声明。但是官方的页面中有很多链接，需要梳理一下学习路径（类似一本字典）。
初始化ros节点是一个ros下的一个init函数
```ros::init(argc,argv,"name",options);```
参数有四个：
1. argc：封装实参个数
2. argv：封装实参的数组
3. 字符串名称：为我们运行的节点命名，具有唯一性
4. options（即可选）：节点启动选项
*当有重名的节点启动时，之前启动的节点会被关闭，所以我们需要一个节点多次启动的时候就可以用options*
```ros：：init_options::AnnoymousName```
这样可以每次启动节点的时候在后面添加一个随机数。
---
**使用**
5. argc，argv的使用
按照ROS格式传入实参，那么ROS可以加以使用,（特定的格式）比如用来设置参数，为节点重命名等等。
6. options的使用

### 话题与服务端对象
话题和服务对象一般都由nodehandle创建，再通过创建的对象。
以发布者对象为例子：
作用：创建发布者对象
模板：被发布的消息类型
参数：
		1. 话题名
		2. 队列长度
		3. latch（可选）若是ture，会保留发布方最后一条消息，新的订阅方连接到发布方时，发布方会将这条信息发送给订阅者。
		


### 回旋函数的使用
spin（）和spinonce（）用于处理回调函数
- spin（）是进入了循环执行回调函数
- spinonce（）只会执行一次回调函数，不会循环，一般用于循环体里面处理回调函数。


### 时间相关的api
1. 获取或者设置时刻
注意要先初始化，再创建句柄，否则无法实现时间操作。
如下所示
```
ros::init(argc,argv,"hello_time");
ros::NodeHandle nh;//必须创建句柄，否则时间没有初始化，导致后续API调用失败
ros::Time right_now = ros::Time::now();//将当前时刻封装成对象
ROS_INFO("当前时刻:%.2f",right_now.toSec());//获取距离 1970年01月01日 00:00:00 的秒数
ROS_INFO("当前时刻:%d",right_now.sec);//获取距离 1970年01月01日 00:00:00 的秒数

ros::Time someTime(100,100000000);// 参数1:秒数  参数2:纳秒
ROS_INFO("时刻:%.2f",someTime.toSec()); //100.10
ros::Time someTime2(100.3);//直接传入 double 类型的秒数
ROS_INFO("时刻:%.2f",someTime2.toSec()); //100.30
```



设置一个时间区间
```
ROS_INFO("当前时刻:%.2f",ros::Time::now().toSec());
ros::Duration du(10);//持续10秒钟,参数是double类型的，以秒为单位
du.sleep();//按照指定的持续时间休眠
ROS_INFO("持续时间:%.2f",du.toSec());//将持续时间换算成秒
ROS_INFO("当前时刻:%.2f",ros::Time::now().toSec());


```
持续时间与时刻运算
```
ROS_INFO("时间运算");
ros::Time now = ros::Time::now();
ros::Duration du1(10);
ros::Duration du2(20);
ROS_INFO("当前时刻:%.2f",now.toSec());
//1.time 与 duration 运算
ros::Time after_now = now + du1;
ros::Time before_now = now - du1;
ROS_INFO("当前时刻之后:%.2f",after_now.toSec());
ROS_INFO("当前时刻之前:%.2f",before_now.toSec());

//2.duration 之间相互运算
ros::Duration du3 = du1 + du2;
ros::Duration du4 = du1 - du2;
ROS_INFO("du3 = %.2f",du3.toSec());
ROS_INFO("du4 = %.2f",du4.toSec());
//PS: time 与 time 不可以运算
// ros::Time nn = now + before_now;//异常
```
设置运行频率
```
ros::Rate rate(1);//指定频率
while (true)
{
    ROS_INFO("-----------code----------");
    rate.sleep();//休眠，休眠时间 = 1 / 频率。
}
```
定时器
```
ros::NodeHandle nh;//必须创建句柄，否则时间没有初始化，导致后续API调用失败

 // ROS 定时器
 /**
* \brief 创建一个定时器，按照指定频率调用回调函数。
*
* \param period 时间间隔
* \param callback 回调函数
* \param oneshot 如果设置为 true,只执行一次回调函数，设置为 false,就循环执行。
* \param autostart 如果为true，返回已经启动的定时器,设置为 false，需要手动启动。
*/
 //Timer createTimer(Duration period, const TimerCallback& callback, bool oneshot = false,
 //                bool autostart = true) const;

 // ros::Timer timer = nh.createTimer(ros::Duration(0.5),doSomeThing);
 ros::Timer timer = nh.createTimer(ros::Duration(0.5),doSomeThing,true);//只执行一次

 // ros::Timer timer = nh.createTimer(ros::Duration(0.5),doSomeThing,false,false);//需要手动启动
 // timer.start();
 ros::spin(); //必须 spin
```
定时器的回调函数
```
void doSomeThing(const ros::TimerEvent &event){
    ROS_INFO("-------------");
    ROS_INFO("event:%s",std::to_string(event.current_real.toSec()).c_str());
}
```
### 其他常用api
当节点的状态出现了变化，我们可以使用```ros::ok()```来判断节点是否正常，而我们往往可以通过与日志相关的函数来判断。
如下为一些日志函数
```
ROS_DEBUG("hello,DEBUG"); //不会输出
ROS_INFO("hello,INFO"); //默认白色字体
ROS_WARN("Hello,WARN"); //默认黄色字体
ROS_ERROR("hello,ERROR");//默认红色字体
ROS_FATAL("hello,FATAL");//默认红色字体
```
### 自定义头文件的调用
1. 可以设计头文件，可执行文件本身作为源文件。
如下图所示：
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
2. 然后我们需要创建可执行文件，如果我们要调用上述头文件的话我们需要配置环境。
3. 编译一下
### 自定义源文件调用
主要是剥离源文件与可执行文件。
1. 把头文件写好之后配置一下环境
2. 分别新建源文件与可执行文件。
3. 然后在cmakelist里面分别配置源文件与头文件。如下所示
头文件与源文件
```
include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

## 声明C++库
add_library(head
  include/test_head_src/haha.h
  src/haha.cpp
)

add_dependencies(head ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(head
  ${catkin_LIBRARIES}
)
```
可执行文件配置
```
add_executable(use_head src/use_head.cpp)

add_dependencies(use_head ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#此处需要添加之前设置的 head 库
target_link_libraries(use_head
  head
  ${catkin_LIBRARIES}
)
```
