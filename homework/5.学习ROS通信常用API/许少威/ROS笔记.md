参考文档：http://www.autolabor.com.cn/book/ROSTutorials/

# 1. 关于双系统


## 1.1 双系统下载：


1. 先在虚拟机中试安装Ubuntu，熟悉一下linux操作系统的操作方式，确保安装Ubuntu双系统后能够完成基础配置操作

2. 准备安装Ubuntu：下载镜像，刻录启动盘

3. 建立分区方案：分出独立的100G来运行Ubuntu

4. 安琥Ubuntu：重启进入BIOS，选择U盘进入，开始安装Ubuntu,具体操作步骤详见： [装了5次Ubuntu，告诉你win10+Ubuntu双系统的正确打开方式](https://zhuanlan.zhihu.com/p/101307629) 
5. 在 ***更新和其他软件*** 界面选择 **正常安装** 

6. 如果只有一个空分区，在 ***安装类型*** 界面可以选择**与Windows共存**，正常情况下建议选择第三项**其他选项**，然后自己选择划分好的分区进行安装

7. 引导界面自定义：在 ***安装选项*** 中选择**与Windows共存**的话，开机界面将会是Ubuntu系统的引导界面，默认进入Ubuntu，而且不好看，硬要美化可以查看[这篇文章](https://blog.csdn.net/qq_38962621/article/details/87887265]) ，更多方法详见之后的美化篇；在**安装选项**中选择其他选项的话，可以在Windows系统中下载 *微pe工具箱* 一键定制引导界面


## 1.2 安装好后可能遇到的问题


### 1. 打不开软件中心：

详见： [Ubuntu 20.04软件中心问题](https://blog.csdn.net/ydyuse/article/details/106494380) 


### 2. 怎么切换中文：

1. 在下载安装的时候如果选择了中文键盘布局，可以直接键盘**control + 空格**切换中文输入；没选择中文键盘布局：可以参考这篇博客： [Ubuntu中文设置与安装中文输入法（超详细）](https://blog.csdn.net/fr16021028/article/details/125891812) ；

2. 如果觉得自带输入法十分难用，想要下载[搜狗输入法](https://shurufa.sogou.com/linux )：安装配置方法详见： [ubuntu下安装使用搜狗拼音输入法，最好用的中文输入法](https://www.bilibili.com/video/BV1gA411t7HH/?spm_id_from=333.337.search-card.all.click) 


### 3. 浏览器哔哩哔哩视频黑屏无法播放：

下载**ffmpeg** ，方法详见： [ubuntu系统Firefox浏览器B站视频无法播放](https://blog.csdn.net/yscan1/article/details/128370844) 


### 4. 声音伪输出：

视频播着播着突然就黑屏注销了，重新输入密码进入系统后就没声音了，打开设置，查看声音输出方式为**伪输出** 。

解决方法：暂时找不到，浏览器输入关键词：*Ubuntu20.04声音伪输出* ，并无有效解决方法，**重启可解决** 


### 5. 双系统时间不对：

让Ubuntu使用Windows的时间管理方式，详见： [解决windows/ubuntu双系统windows时间显示异常问题](https://blog.csdn.net/weixin_42508641/article/details/123569327) 


### 6. 点击右键没有**新建文件**的选项：

新建模板，详见： [ubuntu系统鼠标右键没有新建文档的解决方案](https://blog.csdn.net/qq_49641239/article/details/126029665) 


### 7. 怎么安装软件：

^79081a

1. 软件商店里有的软件直接在软件商店下载安装

2. 软件商店里没有的软件可以上浏览器查找，下载有***amd64*** ， ***x64***  和 ***.deb*** 关键字眼的软件安装包，双击打开安装包运行安装

3. 双击没反应的话：右键安装包>属性>权限>赋予执行权限

4. 也可以选择***64位*** 的 ***.AppImage*** 文件后缀的安装包同样双击 *（如果有弹出是否将软件集成到程序菜单中的窗口，同意或不同意都可运行软件，与Windows系统中创建快捷方式同理）*

5. 命令行安装方式：打开安装包所在文件夹，在文件夹下打开终端输入：
```
chmod +x 安装包名称
```

^3bfa4a

赋予执行权限，然后使用
```
sudo dpkg -i 安装包名称
```

^f494b9

进行命令行安装


### 8. 我下载的软件为什么找不到/为什么我每次打开软件都要用到终端：

终端打开软件超级超级帅的，但是手贱把终端关掉之后软件会跟着关掉这真的难崩，有没有办法实现类似Windows上创建桌面快捷方式的操作呢？
1. 点击文件夹

2. 键盘**control + H** 显示隐藏文件

3. 进入 **.local/share/applications** 文件夹，在此文件夹下打开终端，创建 **{文件名}.desktop** 文件，代码格式详见： [Linux下 创建启动器（.Desktop文件)](https://blog.csdn.net/hebbely/article/details/102459754) 


### 9. 在终端下载东西太慢了：

换源：**鱼香ROS**支持一键换源： ![[ROS笔记#^f50447]]
### 10. 经常卡死，性能调度不积极：

Ubuntu默认CPU处于省点模式，会以最低频率运行，可以自定义CPU性能模式：详见： [ubuntu系统CPU性能模式设置](https://www.cnblogs.com/xyf9474/p/16303596.html) 


### 11. 安装WPS：

在浏览器下载WPS的deb文件后发现双击安装不了，可以使用命令行安装![[ROS笔记#^3bfa4a]]
![[ROS笔记#^f494b9]]


## 1.3 关于科学上网


### 1. 有在Windows或者手机端租用机场科学上网经验

可以了解一下Clash，方法之一：

1. 下载clash for Windows linux（没写错，名字就是这样）

2. 将自己的机场链接导入软件获取节点信息

3.  如果节点信息不可用，说明节点协议不是clash，使用clash节点转换器将节点信息转换为clash协议

### 2. 无科学上网经验

朋友先别急，缘分到了自然就会了（doge）


# 2. ROS基础


## 2.1 安装ROS


1. 鱼香ROS 鱼香ROS 鱼香ROS 鱼香ROS 鱼香ROS 鱼香ROS 鱼香ROS ！！！！
```
wget http://fishros.com/install -O fishros && . fishros

```
^f50447

2. 首先是换源，选择**5**
3. 其次是安装ROS，选择**1**
4. 配置依赖，选择**3**
5. 配置环境变量，选择**4**

想要自己配置的话可以详见[【Autolabor初级教程】ROS机器人入门](https://www.bilibili.com/video/BV1Ci4y1L7ZZ/?p=35&spm_id_from=pageDriver&vd_source=e5dd4eeeb267997c7ce9703f7cca56f2) 

## 2.2 测试ROS

ROS 内置了一些小程序，可以通过运行这些小程序以检测 ROS 环境是否可以正常运行

1. 首先启动三个命令行(ctrl + alt + T)

2. 命令行1键入：roscore

3. 命令行2键入：rosrun turtlesim turtlesim_node(此时会弹出图形化界面)

4. 命令行3键入：rosrun turtlesim turtle_teleop_key(在3中可以通过上下左右控制2中乌龟的运动)


## 2.3 运行ROS

1. 创建工作空间并初始化：
```
mkdir -p 自定义空间名称/src
cd 自定义空间名称
catkin_make
```
2. 在工作空间中新建功能包
```
cd src
catkin_create_pkg 自定义ROS包名 roscpp rospy std_msgs
```
3. 编写源文件：pass
4. 配置 ros 包下的 **Cmakelist.txt** 文件
5. 终端运行：
	1. 启动ros核心：
	```
	roscore
	```
	2. 设置环境变量：
	```
	cd 自定义空间
	source devel/setup.bash
	```
	3. 运行节点
	```
	rosrun 功能包名 节点源文件名
	```
	4. 运行计算图：
	```
	rqt_graph
	```

2. launch文件运行：
	1. 在功能包中创建launch文件夹，在文件夹中创建launch文件，launch文件运行会自动开启ros核心，无需再开一个终端运行ros核心
	2. 运行launch文件:
	```
	roslaunch 功能包名 launch文件名
	```



## 2.4 集成开发环境的搭建


### VScode
1. 下载
VScode for linux下载：https://code.visualstudio.com/docs/setup/linux

2. 安装
 详见[[ROS笔记#7. 怎么安装软件：]]

3. 环境配置详见教程



# 3. ROS通信机制

## 3.1 话题通信

#### 概念

以发布订阅的方式实现不同节点之间数据交互的通信模式。


#### 角色 

1. master --> 管理者
2. talker --> 发布者
3. listener --> 订阅者

![[Pasted image 20230403223646.jpg]]

#### 注意

1. 使用的协议有 rtc 和 tcp
2. 步骤0和1没有顺序关系
3. talker 和 listener 可以存在多个
4. talker 和 listener 建立连接后，master就可以关闭了
5. 上述实现流程已经封装了，以后可以直接调用即可

#### 主要关注点

0. 大部分实现已经被封装了
1. 话题设置
2. 关注发布者实现
3. 关注订阅者实现
4. 关注消息载体


### 3.1.1 话题通信基本操作（C++）

#### 需求

编写发布订阅实现，要求发布方以10HZ的频率发布文本消息， 订阅方订阅消息并将消息内容打印输出

#### 分析

ROS master不需要实现，主要关注以下三点：
1. 发布方
2. 接收方
3. 数据

#### 流程

1. 编写发布方实现
2. 编写订阅方实现
3. 编写配置文件
4. 编译运行

##### 1. 发布方
```C++
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
/*
发布方实现：
1. 包含头文件
ROS中的文本类型 --> std_msgs/String.h
2. 初始化ROS节点
3. 创建节点句柄
4. 创建发布者对象
5. 编写发布逻辑并发布数据
*/
int main(int argc, char *argv[])
{
setlocale(LC_ALL,"");

// 2. 初始化ROS节点
ros::init(argc,argv,"erGouZi");

// 3. 创建节点句柄
ros::NodeHandle nh;

// 4. 创建发布者对象
ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);

// 5. 编写发布逻辑并发布数据
//要求以10HZ频率发布数据，并且文本后添加编号
//先创建被发布的消息
std_msgs::String msg;

//发布频率
ros::Rate rate(10);

//设置编号
int count = 0;

//编写循环，循环中发布数据
while (ros::ok())
{
count++;
//实现字符串拼接数字

std::stringstream ss;
ss << "hello ---> " << count;
//msg.data = "hello";
msg.data = ss.str();

pub.publish(msg);

//添加日志
ROS_INFO("发布的数据是：%s",ss.str().c_str());

rate.sleep();
}
return 0;
}
```


##### 2. 订阅方

```C++
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
/*
订阅方实现：
1. 包含头文件
ROS中的文本类型 --> std_msgs/String.h
2. 初始化ROS节点
3. 创建节点句柄
4. 创建订阅者对象
5. 处理订阅到的数据    
*/  
void doMsg(const std_msgs::String::ConstPtr &msg){
ROS_INFO("订阅到的数据是：%s",msg->data.c_str());
}
  
int main(int argc, char *argv[])
{
setlocale(LC_ALL,"");

// 2. 初始化ROS节点
ros::init(argc,argv,"cuiHua");
  
// 3. 创建节点句柄
ros::NodeHandle nh;
  
// 4. 创建订阅者对象
ros::Subscriber sub = nh.subscribe("fang",10,doMsg);

// 5. 处理订阅到的数据
ros::spin();
  
return 0;

}
```


### 3.1.2 自定义消息格式

#### 说明

自带消息格式较为单一，复合的消息格式需要自定义

#### 实现步骤

详见 [文档](http://www.autolabor.com.cn/book/ROSTutorials/di-2-zhang-ros-jia-gou-she-ji/22hua-ti-tong-xin/214-hua-ti-tong-xin-zhi-zi-ding-yi-xiao-xi.html) 

1. 定义msg文件，在功能包下创建msg目录 **(不要在src文件夹内创建)** ，新建 **.msg** 文件，在文件中编写数据格式
2. 编辑配置文件
3. 编译

#### 调用

**调用头文件抛出异常：** vscode配置：
```json
{
    "configurations": [
        {
            "browse": {
                "databaseFilename": "",
                "limitSymbolsToIncludedHeaders": true
            },
            "includePath": [
                "/opt/ros/noetic/include/**",
                "/usr/include/**",
                "/xxx/yyy工作空间/devel/include/**" //配置 head 文件的路径 
            ],
            "name": "ROS",
            "intelliSenseMode": "gcc-x64",
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c11",
            "cppStandard": "c++17"
        }
    ],
    "version": 4
}

```
**发布方实现：**
```c++
/*
    需求: 循环发布人的信息

*/
#include "ros/ros.h"
#include "demo02_talker_listener/Person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //1.初始化 ROS 节点
    ros::init(argc,argv,"talker_person");
    //2.创建 ROS 句柄
    ros::NodeHandle nh;
    //3.创建发布者对象
    ros::Publisher pub = nh.advertise<demo02_talker_listener::Person>("chatter_person",1000);
    //4.组织被发布的消息，编写发布逻辑并发布消息
    demo02_talker_listener::Person p;
    p.name = "sunwukong";
    p.age = 2000;
    p.height = 1.45;

    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(p);
        p.age += 1;
        ROS_INFO("我叫:%s,今年%d岁,高%.2f米", p.name.c_str(), p.age, p.height);

        r.sleep();
        ros::spinOnce();
    }
    return 0;
}
```

**订阅方实现：**

```c++
/*
    需求: 订阅人的信息

*/
#include "ros/ros.h"
#include "demo02_talker_listener/Person.h"

void doPerson(const demo02_talker_listener::Person::ConstPtr& person_p){
    ROS_INFO("订阅的人信息:%s, %d, %.2f", person_p->name.c_str(), person_p->age, person_p->height);
}

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");

    //1.初始化 ROS 节点
    ros::init(argc,argv,"listener_person");
    //2.创建 ROS 句柄
    ros::NodeHandle nh;
    //3.创建订阅对象
    ros::Subscriber sub = nh.subscribe<demo02_talker_listener::Person>("chatter_person",10,doPerson);

    //4.回调函数中处理 person

    //5.ros::spin();
    ros::spin();    
    return 0;
}
```
**配置CMakeList.txt文件：**

需要添加 **add_dependencies** 用以设置所依赖的消息相关的中间文件。
```CMake
add_executable(person_talker src/person_talker.cpp)
add_executable(person_listener src/person_listener.cpp)



add_dependencies(person_talker ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(person_listener ${PROJECT_NAME}_generate_messages_cpp)


target_link_libraries(person_talker
  ${catkin_LIBRARIES}
)
target_link_libraries(person_listener
  ${catkin_LIBRARIES}
)

```

### 3.1.3 在一个节点里同时实现订阅与发布

详见 [ROS学习|用一个节点订阅和发布多个话题](https://juejin.cn/post/7133025159237074981) 



## 3.2 服务通信

### 3.2.1 概念

以请求响应的方式实现不同节点之间数据交换的通讯模式


### 3.2.2 服务通信理论模型

服务通信较之于话题通信更简单些，理论模型如下图所示，该模型中涉及到三个角色:

1. ROS master(管理者)
2. Server(服务端)
3. Client(客户端)

ROS Master 负责保管 Server 和 Client 注册的信息，并匹配话题相同的 Server 与 Client ，帮助 Server 与 Client 建立连接，连接建立后，Client 发送请求信息，Server 返回响应信息。

![](http://www.autolabor.com.cn/book/ROSTutorials/assets/02_%E6%9C%8D%E5%8A%A1%E9%80%9A%E4%BF%A1%E6%A8%A1%E5%9E%8B.jpg)

整个流程由以下步骤实现:

#### 0.Server注册

Server 启动后，会通过RPC在 ROS Master 中注册自身信息，其中包含提供的服务的名称。ROS Master 会将节点的注册信息加入到注册表中。

#### 1.Client注册

Client 启动后，也会通过RPC在 ROS Master 中注册自身信息，包含需要请求的服务的名称。ROS Master 会将节点的注册信息加入到注册表中。

#### 2.ROS Master实现信息匹配

ROS Master 会根据注册表中的信息匹配Server和 Client，并通过 RPC 向 Client 发送 Server 的 **TCP** 地址信息。

#### 3.Client发送请求

Client 根据步骤2 响应的信息，使用 TCP 与 Server 建立网络连接，并发送请求数据。

#### 4.Server发送响应

Server 接收、解析请求的数据，并产生响应结果返回给 Client。

> 注意:
> 
> 1.客户端请求被处理时，需要保证服务器已经启动；
> 
> 2.服务端和客户端都可以存在多个。

### 3.2.3 服务通信自定义srv

#### 需求
> 服务

### 3.2.4 服务通信基本操作（C++）

#### 需求

#### 关注点

1. 话题
2. 服务端
3. 客户端
4. 数据载体

#### 流程

##### 1. 服务端

```C++
#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"

bool doNums(plumbing_server_client::Addints::Request &request,plumbing_server_client::Addints::Response &response){

int num1 = request.num1;
int num2 = request.num2;
ROS_INFO("收到的请求数据:num1 = %d,num2 = %d",num1,num2);

int sum = num1 + num2;

response.sum = sum;
ROS_INFO("求和结果:sum = %d",sum);  
return true;
}

int main(int argc, char *argv[])
{
setlocale(LC_ALL,"");
  
ros::init(argc,argv,"heiShui");
  
ros::NodeHandle nh;  

ros::ServiceServer server = nh.advertiseService("addInts",doNums);

ROS_INFO("服务端启动");
  
ros::spin();

return 0;
}
```
##### 2. 客户端

```C++
#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"
    
int main(int argc, char *argv[])
{
setlocale(LC_ALL,"");
  
ros::init(argc,argv,"daBao");
  
ros::NodeHandle nh;
  
ros::ServiceClient client = nh.serviceClient<plumbing_server_client::Addints>("addInts");

ROS_INFO("客户端启动");
  
ros::service::waitForService("addInts");
  
plumbing_server_client::Addints ai;

ai.request.num1 = atoi(argv[1]);
ai.request.num2 = atoi(argv[2]);
  
client.waitForExistence();
  
bool flag = client.call(ai);
 
if (flag)
{
ROS_INFO("响应成功！");

ROS_INFO("响应结果 = %d",ai.response.sum);
} else {
ROS_INFO("处理失败！");
}  
return 0;
}
```

### 3.2.5 客户端优化

#### 等待响应

在正常使用中，可能出现客户端比服务端早打开的情况，此时客户端会报错，因此优化客户端令其等待服务端响应是十分有必要的：

```c++
//方式1
ros::service::waitForSerice("AddInts");
//方式2
client.waitForExistence();
```
#### 动态传值

向服务器传输的值应当是多变的，而不会写死在程序中，我们可以通过获取arcv中的值来进行参数的动态传输：
```c++
//例如运行：rosrun 包名 文件名 34 65
//此时传入两个参数：34 和 65
//argc的值是3，argv[1] = 34,argv[2] = 65
//因此我们可以通过如下修改优化：
ai.request.num1 = atoi(argv[1]);
ai.request.num2 = atoi(argv[2]);//atoi()用来强制转换为int类型
```

## 3.3 参数服务器

### 3.3.1 概念

以共享的方式实现不同节点之间的数据交互的通讯模式

### 3.3.2 作用

储存一些节点的共享数据，类似于全局变量

### 3.3.3 参数服务器基本操作

#### 需要的基本操作

增删改查

##### 1. 增：

```c++
#include "ros/ros.h"
  
int main(int argc, char *argv[])
{
setlocale(LC_ALL,"");
  
ros::init(argc,argv,"set_param_c");
  
ros::NodeHandle nh;
  
//增 方法1
nh.setParam("type","xiaohuang");

//增 方法2
ros::param::set("radius",0.15);
  
//改 同增↑
nh.setParam("radius",0.1234);//只要键是已经存在的，值就会覆盖
  
return 0;
}
```


##### 2. 改、查：

```c++
    //在 roscpp 中提供了两套 API 实现参数操作
    //第一种方案：
    ros::NodeHandle nh;

        nh.param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        nh.getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        nh.getParamCached键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        nh.getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        nh.hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        nh.searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

	//第二种方案：
	ros::param--- 与上述类似
	
```


##### 3. 删
```c++
#include "ros/ros.h"  
/*删除操作：
ros::NodeHandle
deleteParam("键")

根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false
  
ros::param
del("键")

根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false  
*/
  
int main(int argc, char *argv[])
{
setlocale(LC_ALL,"");

ros::init(argc,argv,"param_del_c");  
ros::NodeHandle nh;
  
bool flag1 = nh.deleteParam("type");
  
if (flag1)
{
ROS_INFO("删除成功");
}
else
{
ROS_INFO("删除失败");
}

return 0;
}
```

## 3.4 ROS常用命令

机器人系统中启动的节点少则几个，多则十几个、几十个，不同的节点名称各异，通信时使用话题、服务、消息、参数等等都各不相同，一个显而易见的问题是: 当需要自定义节点和其他某个已经存在的节点通信时，如何获取对方的话题、以及消息载体的格式呢？

在 ROS 同提供了一些实用的命令行工具，可以用于获取不同节点的各类信息，常用的命令如下:

*   rosnode : 操作节点
-   rostopic : 操作话题
-   rosservice : 操作服务
-   rosmsg : 操作msg消息
-   rossrv : 操作srv消息
-   rosparam : 操作参数

**另请参考:**

-   [http://wiki.ros.org/ROS/CommandLineTools](http://wiki.ros.org/ROS/CommandLineTools)

![](http://www.autolabor.com.cn/book/ROSTutorials/assets/ROS%E5%91%BD%E4%BB%A4%E8%A1%8C%E5%B7%A5%E5%85%B7.PNG)


### 3.4.1 rosnode

```
rosnode ping    测试到节点的连接状态
rosnode list    列出活动节点
rosnode info    打印节点信息
rosnode machine    列出指定设备上节点
rosnode kill    杀死某个节点
rosnode cleanup    清除不可连接的节点
```

### 3.4.2 rostopic

```
rostopic bw     显示主题使用的带宽
rostopic delay  显示带有 header 的主题延迟
rostopic echo   打印消息到屏幕
rostopic find   根据类型查找主题
rostopic hz     显示主题的发布频率
rostopic info   显示主题相关信息
rostopic list   显示所有活动状态下的主题
rostopic pub    将数据发布到主题
rostopic type   打印主题类型
```

### 3.4.3 rosservice

```
rosservice args 打印服务参数
rosservice call    使用提供的参数调用服务
rosservice find    按照服务类型查找服务
rosservice info    打印有关服务的信息
rosservice list    列出所有活动的服务
rosservice type    打印服务类型
rosservice uri    打印服务的 ROSRPC uri
```
### 3.4.4 rosmsg

```
rosmsg show    显示消息描述
rosmsg info    显示消息信息
rosmsg list    列出所有消息
rosmsg md5    显示 md5 加密后的消息
rosmsg package    显示某个功能包下的所有消息
rosmsg packages    列出包含消息的功能包
```

### 3.4.5 rossrv

```
rossrv show    显示服务消息详情
rossrv info    显示服务消息相关信息
rossrv list    列出所有服务信息
rossrv md5    显示 md5 加密后的服务消息
rossrv package    显示某个包下所有服务消息
rossrv packages    显示包含服务消息的所有包
```

### 3.4.6 rosparam

```
rosparam set    设置参数
rosparam get    获取参数
rosparam load    从外部文件加载参数
rosparam dump    将参数写出到外部文件
rosparam delete    删除参数
rosparam list    列出所有参数
```

## 3.5 通讯机制实操

### 3.5.1 话题发布

 #### 实现流程

1.  通过计算图结合ros命令获取话题与消息信息。
2.  编码实现运动控制节点。
3.  启动 roscore、turtlesim_node 以及自定义的控制节点，查看运行结果。

```c++
#include "ros/ros.h"  
#include "geometry_msgs/Twist.h"  

int main(int argc, char *argv[])  
{  
//初始化ros节点
ros::init(argc,argv,"my_control"); 
//初始化节点句柄
ros::NodeHandle nh;   

//创建发布对象
ros::Publisher pub =  nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",10);  

//设置发布频率
ros::Rate rate(10);  
//创建发布消息对象
geometry_msgs::Twist twist;  
//设置参数
twist.linear.x = 1.0;  
twist.linear.y = 0.0;  
twist.linear.z = 0.0;  
twist.angular.x = 0.0;  
twist.angular.y = 0.0;  
twist.angular.z = 0.5;  

//发布
while (ros::ok())  
{  
pub.publish(twist);  
rate.sleep();  
ros::spinOnce();  
}  
return 0;  
}
```

### 3.5.2 话题订阅

#### 实现流程

1.  通过ros命令获取话题与消息信息。
2.  编码实现位姿获取节点。
3.  启动 roscore、turtlesim_node 、控制节点以及位姿订阅节点，控制乌龟运动并输出乌龟的位姿。

```c++
#include "ros/ros.h"  
#include "turtlesim/Pose.h"  
  
void doPose(const turtlesim::Pose::ConstPtr& p){  
ROS_INFO("乌龟位姿信息:x=%.2f,y=%.2f,theta=%.2f,lv=%.2f,av=%.2f",  
p->x,p->y,p->theta,p->linear_velocity,p->angular_velocity);  
}  //回调函数
  
int main(int argc, char *argv[])  
{  
setlocale(LC_ALL,"");//解决乱码问题  
ros::init(argc,argv,"sub_pose");  

ros::NodeHandle nh;  

ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);  

ros::spin();  
return 0;  
}
```

### 3.5.3 服务调用

#### 实现流程

1.  通过ros命令获取服务与服务消息信息。
2.  编码实现服务请求节点。
3.  启动 roscore、turtlesim_node 、乌龟生成节点，生成新的乌龟。

```c++
#include "ros/ros.h"  
#include "turtlesim/Spawn.h"  
  
int main(int argc, char *argv[])  
{  
setlocale(LC_ALL,"");  
  
ros::init(argc,argv,"servive_call");  
  
ros::NodeHandle nh;  

//创建客户端对象
ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");  
  
turtlesim::Spawn spawn;  
//设置请求参数
spawn.request.name = "turtle2";  
spawn.request.theta = 1.57;  
spawn.request.x = 3;  
spawn.request.y = 5;  

//等待服务器启动，发送请求
client.waitForExistence();  
bool flag = client.call(spawn);  
  
if (flag)  
{  
ROS_INFO("新的小海龟生成：名字：%s",spawn.request.name.c_str());  
}  
else  
{  
ROS_INFO("小海龟生成失败!");  
}  
  
return 0;  
}
```

### 3.5.4 参数设置

#### 实现流程

1.  通过ros命令获取参数。
2.  编码实现服参数设置节点。
3.  启动 roscore、turtlesim_node 与参数设置节点，查看运行结果。

```c++
#include "ros/ros.h"  
  
int main(int argc, char *argv[])  
{  
ros::init(argc,argv,"change_bgColor");  
//用ros::param::set可以不用创建节点句柄
ros::param::set("/turtlesim/background_r",0);  
ros::param::set("/turtlesim/background_g",0);  
ros::param::set("/turtlesim/background_b",0);  
return 0;  
}
```

## 3.5 ROS通信机制进阶

### 3.5.1 初始化

```c++
void init(int &argc, char **argv, const std::string& name, uint32_t options = 0);
```

**argc** 参数个数
**argv** 参数列表
**name** 节点名称，需要保证其唯一性，不允许包含命名空间
**options** 节点启动选项，被封装进了ros::init_options

**代码示例：** 
```c++
#include "ros/ros.h"
int main(int argc, char *argv[])
{
ros::init(argc,argv,"name",ros::init_options::AnonymousName);
return 0;
//
}
```
它可以在节点名后面产生一个随机数值，解决节点重名问题）

**在终端中运行该节点** 可以在后面使用 **__参数 := ?** 的方法来传入参数

例如：
```shell
rosrun plumbing_apis demo01_apis_pub _lenth:=2
```
向这个 demo01_apis_pub 这个节点的参数服务器中传入了 lenth = 2 这个参数，查询结果为：

/demo01_apis_pub/lenth = 2 

### 3.5.2 话题与服务相关对象

#### 1.发布对象

##### 对象获取:

```c++
template <class M>
Publisher advertise(const std::string& topic, uint32_t queue_size, bool latch = false)
```

**topic** 发布消息使用的话题
**queue_size** 等待发送给订阅者的最大消息数量
**latch (optional)** 如果为 true,该话题发布的最后一条消息将被保存，并且后期当有订阅者连接时会将该消息发送给订阅者
**return** 调用成功时，会返回一个发布对象

**使用示例：**

```c++
ros::Publisher pub = handle.advertise<std_msgs::Empty>("my_topic", 1, true);
```

##### 消息发布函数:

```c++
template <typename M>
void publish(const M& message) const
```

**message** 要发布的消息

**使用示例：**
```c++
std_msgs::String msgs;

pub.publish(msgs);
```

#### 2.订阅对象

##### 对象获取:

```c++
void callback(const std_msgs::Empty::ConstPtr& message){...}
ros::NodeHandle nodeHandle;
ros::Subscriber sub = nodeHandle.subscribe("my_topic", 1, callback);
if (sub) // Enter if subscriber is valid
{
...
}

template<class M>
Subscriber subscribe(const std::string& topic, uint32_t queue_size, void(*fp)(const boost::shared_ptr<M const>&), const TransportHints& transport_hints = TransportHints())
```
该函数将根据给定的话题在ROS master 注册，并自动连接相同主题的发布方，每接收到一条消息，都会调用回调函数，并且传入该消息的共享指针，**该消息不能被修改**，因为可能其他订阅对象也会使用该消息（使用const的修饰的原因）。


**M** 消息类型
**topic** 订阅的话题
**queue_size** 消息队列长度，超出长度时，头部的消息将被弃用
**fp** 当订阅到一条消息时，需要执行的回调函数
**return** 调用成功时，返回一个订阅者对象，失败时，返回空对象


**使用示例：**
```c++
void callback(const std_msgs::Empty::ConstPtr& message)
{
}

ros::Subscriber sub = handle.subscribe("my_topic", 1, callback);
```

#### 3.服务对象

##### 对象获取:

```c++
template<class MReq, class MRes>
ServiceServer advertiseService(const std::string& service, bool(*srv_func)(MReq&, MRes&))
```
该函数可以连接到 ROS master，并提供一个具有给定名称的服务对象。

**service** 服务的主题名称
**srv_func** 接收到请求时，需要处理请求的回调函数
**return** 请求成功时返回服务对象，否则返回空对象

**使用示例：**
```c++
bool callback(std_srvs::Empty& request, std_srvs::Empty& response)
{
return true;
}

ros::ServiceServer service = handle.advertiseService("my_service", callback);

```


#### 4.客户端对象

##### 对象获取:

```c++
/** 
  * @brief 创建一个服务客户端对象
  *
  * 当清除最后一个连接的引用句柄时，连接将被关闭。
  *
  * @param service_name 服务主题名称
  */
 template<class Service>
 ServiceClient serviceClient(const std::string& service_name, bool persistent = false, 
                             const M_string& header_values = M_string())
```

##### 请求发送函数:

```c++
/**
   * @brief 发送请求
   * 返回值为 bool 类型，true，请求处理成功，false，处理失败。
   */
  template<class Service>
  bool call(Service& service)
```

##### 等待服务函数1:

```c++
/**
 * ros::service::waitForService("addInts");
 * \brief 等待服务可用，否则一致处于阻塞状态
 * \param service_name 被"等待"的服务的话题名称
 * \param timeout 等待最大时常，默认为 -1，可以永久等待直至节点关闭
 * \return 成功返回 true，否则返回 false。
 */
ROSCPP_DECL bool waitForService(const std::string& service_name, ros::Duration timeout = ros::Duration(-1));
```

##### 等待服务函数2:

```c++
/**
* client.waitForExistence();
* \brief 等待服务可用，否则一致处于阻塞状态
* \param timeout 等待最大时常，默认为 -1，可以永久等待直至节点关闭
* \return 成功返回 true，否则返回 false。
*/
bool waitForExistence(ros::Duration timeout = ros::Duration(-1));
```


### 3.5.3 回旋函数

#### 1.spinOnce()

```c++
/**
 * \brief 处理一轮回调
 *
 * 一般应用场景:
 *     在循环体内，处理所有可用的回调函数
 * 
 */
ROSCPP_DECL void spinOnce();
```

#### 2.spin()

```c++
/** 
 * \brief 进入循环处理回调 
 */
ROSCPP_DECL void spin();
```

#### 3.二者比较

**相同点:** 二者都用于处理回调函数；

**不同点:** ros::spin() 是进入了循环执行回调函数，而 ros::spinOnce() 只会执行一次回调函数(没有循环)，在 ros::spin() 后的语句不会执行到，而 ros::spinOnce() 后的语句可以执行。

### 3.5.4 时间

#### 1.时刻

##### 获取时刻，或是设置指定时刻

**使用示例：**
```c++
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

#### 2.持续时间

设置一个时间区间(间隔):

```c++
ROS_INFO("当前时刻:%.2f",ros::Time::now().toSec());
ros::Duration du(10);//持续10秒钟,参数是double类型的，以秒为单位
du.sleep();//按照指定的持续时间休眠
ROS_INFO("持续时间:%.2f",du.toSec());//将持续时间换算成秒
ROS_INFO("当前时刻:%.2f",ros::Time::now().toSec());
```

#### 3.持续时间与时刻运算

为了方便使用，ROS中提供了时间与时刻的运算:

```c++
ROS_INFO("时间运算");
ros::Time now = ros::Time::now();
ros::Duration du1(10);
ros::Duration du2(20);
ROS_INFO("当前时刻:%.2f",now.toSec());
//1.time 与 duration 运算
实现示例：ros::Time after_now = now + du1;
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

#### 4.设置运行频率

```c++
ros::Rate rate(1);//指定频率
while (true)
{
    ROS_INFO("-----------code----------");
    rate.sleep();//休眠，休眠时间 = 1 / 频率。
}
```

#### 5.定时器

ROS 中内置了专门的定时器，可以实现与 ros::Rate 类似的效果:

```c++
Timer createTimer(Duration period, const TimerCallback& callback, bool oneshot = false, bool autostart = true) const;
```
**period** 时间间隔
**callback** 回调函数
**oneshot** 如果设置为 true,只执行一次回调函数，设置为 false,就循环执行。
**autostart** 如果为true，返回已经启动的定时器,设置为 false，需要手动启动。

**使用示例：**
```c++
ros::NodeHandle nh;//必须创建句柄，否则时间没有初始化，导致后续API调用失败

ros::Timer timer = nh.createTimer(ros::Duration(0.5),doSomeThing);
//ros::Timer timer = nh.createTimer(ros::Duration(0.5),doSomeThing,true);只执行一次

//ros::Timer timer = nh.createTimer(ros::Duration(0.5),doSomeThing,false,false);//需要手动启动
// timer.start();
ros::spin(); //必须 spin
```

定时器的回调函数:

```c++
void doSomeThing(const ros::TimerEvent &event){
    ROS_INFO("-------------");
    ROS_INFO("event:%s",std::to_string(event.current_real.toSec()).c_str());
}
//event.current_real.toSec()
```

### 3.5.5 其他函数

#### 1.节点状态判断

```c++
/*
检查节点是否已经退出
ros::shutdown() 被调用且执行完毕后，该函数将会返回 false
*/
bool ok();
```
**return**  true 节点还健在；false 节点已经火化了。

#### 2.节点关闭函数

```c++
/*
关闭节点
*/
void shutdown();
```

#### 3.日志函数

**使用示例：**

```c++
ROS_DEBUG("hello,DEBUG"); //不会输出
ROS_INFO("hello,INFO"); //默认白色字体
ROS_WARN("Hello,WARN"); //默认黄色字体
ROS_ERROR("hello,ERROR");//默认红色字体
ROS_FATAL("hello,FATAL");//默认红色字体
```


### 3.6 ROS的头文件与源文件

#### 3.6.1 自定义头文件调用

##### 流程
1. 编写头文件
2. 编写源文件
3. **编辑配置文件**并执行

##### 编写头文件
```c++
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
##### 在可执行文件里引入头文件

**包含头文件抛出异常问题详见：**[[ROS笔记#3.1 话题通信#调用]]

**使用示例：**

```c++
#include "ros/ros.h"
#include "plumbing_head/hello.h"

namespace hello_ns{
void Myhello::run(){
ROS_INFO("run done!");
	}
}

  

int main(int argc, char *argv[])
{
ros::init(argc,argv,"hello_head");

hello_ns::Myhello myhello;
myhello.run();

return 0;
}
```


#### 3.6.2 自定义源文件调用

##### 流程

1. 编写头文件
2. 编写源文件
3. 编写可执行文件
4. **编写配置文件**并执行

**源文件：**

```c++
#include "ros/ros.h"
#include "plumbing_head/hello.h"

namespace hello_ns{
void Myhello::run(){
ROS_INFO("src_run() done!");
}
}
```

**可执行文件：**

```c++
#include "ros/ros.h"
#include "plumbing_head/hello.h"

int main(int argc, char *argv[])
{
ros::init(argc,argv,"hello_head_src");

hello_ns::Myhello myhello;

myhello.run();

return 0;
}
```

**配置CMakeList.txt**

头文件与源文件相关配置：

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

可执行文件配置：

```
add_executable(use_head src/use_head.cpp)

add_dependencies(use_head ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#此处需要添加之前设置的 head 库
target_link_libraries(use_head
  head
  ${catkin_LIBRARIES}
)
```

# 4. ROS运行管理


