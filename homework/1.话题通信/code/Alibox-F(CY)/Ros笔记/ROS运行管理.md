#ros #vscode 

# 1.元功能包

# 2.launch文件

## -1.launch文件基本实现

## -2.launch文件标签详解

### --1.```<launch>标签  最高优先级```

属性：弃用声明

```
<launch deprecated="此文件已过期">
```

### --2.```<node>标签```
属性：
-   pkg="包名"
    
    节点所属的包
    
-   type="nodeType"
    
    节点类型(可执行文件.cpp)
    
-   name="nodeName"
    
    节点名称(自定义)
    
-   args="xxx xxx xxx" (可选)
    
    将参数传递给节点
    
-   machine="机器名"
    
    在指定机器上启动节点
    
-   respawn="true | false" (可选)
    
    如果节点退出，是否自动重启(可以在kill roscore来关闭)
    
	-   respawn_delay=" N" (可选)
    
	    如果 respawn 为 true, 那么延迟 N 秒后启动节点
    
-   required="true | false" (可选)
    
    该节点是否必须，如果为 true,那么如果该节点退出，将杀死整个 roslaunch
    
-   ns="xxx" (可选)
    
    在指定命名空间 xxx 中启动节点（防止节点重名）
    
-   clear_params="true | false" (可选)
    
    在启动前，删除节点的私有空间的所有参数
    
-   output="log | screen" (可选)
    
    日志发送目标，可以设置为 log 日志文件，或 screen 屏幕,默认是 log,推荐为screen

### --3.```<remap>```话题重命名（node子标签）
-   from="xxx"
    
    原始话题名称
    
-   to="yyy"
    
    目标名称
### --4.```<param>```传参（node子标签）
-   name="命名空间/参数名"
    
    参数名称，可以包含命名空间
    
-   value="xxx" (可选)
    
    定义参数值，如果此处省略，必须指定外部文件作为参数源
    
-   type="str | int | double | bool | yaml" (可选)
    
    指定参数类型
```
    如果未指定，roslaunch 会尝试确定参数类型，规则如下:
    
    如果包含 '.' 的数字解析未浮点型，否则为整型
        
     "true" 和 "false" 是 bool 值(不区分大小写)
        
    其他是字符串
```
两种设置规则：1.设置在node下：参数会添加到node对应的节点
						2.设置在node外：参数会添加到全局

### --5.```<rosparam>```（node子标签）
-   command="load | dump | delete" (可选，默认 load)
    
    加载、导出或删除参数
    
-   file="$(find 包名)/文件夹/执行文件.格式"
    
    加载或导出到的 yaml 文件（yaml文件下参数设置要加空格如：param： param_A）
    **Tips：如果想导出所有参数，可以新建一个launch文件运行dump命令**
    Reason：优先运行param标签
    
-   param="参数名称"
    
-   ns="命名空间" (可选)
设置规则同``<param>
### --6.```<group>```分类防止重名
-   ns="名称空间" (可选)
    
-   clear_params="true | false" (可选)
    
    启动前，是否删除组名称空间的所有参数(慎用....此功能危险)
**TIps:避免重名问题发生，原理是添加命名空间
		1.在gruop下修改节点名称是要带上ns名称**
### --7.```<arg>```
-   name="参数名称"
    
-   default="默认值" (可选)
    
-   value="数值" (可选)
    
    不可以与 default 并存
    
-   doc="描述信息"
**TIps:避免反复修改参数使调参更加灵活
    
### --8.```<include>```
-   file="$(find 包名)/xxx/xxx.launch"
    
    要包含的文件路径
    
-   ns="xxx" (可选)
    
    在指定命名空间导入文件

# 重名问题

## 1.工作空间覆盖（有重名功能包）
无解决方案，可以删除devel和build文件再重新catkin_make

## 【2】.节点重名

### --1.命令行实现（前缀）
``rosrun xxx yyy__ns:=自定义名称
### --2.命令行实现（别名）
``rosrun xxx yyy name/自定义名称
Tips：以上两种可以同时实现
``rosrun xxx yyy __ns:=自定义名称 __name:=自定义名称
(空格别忘/tab补齐后自动空格)
### --3.launch文件解决思路同样（改名字or命名空间）
### --4.编码实现（用ros::init_options---->添加随机数后缀）

## 【3】.话题重名
### --1.命令行实现（发布者）
``rosrun xxx yyy 原话题名称（等待订阅）：=现话题名称（已被订阅）
### --2.命令行实现（订阅者）
同上一样
### --3.launch文件实现（remap实现）
### --4.编码实现
【1】：全局变量（/xxx）
【2】：局部变量（xxx/yyy）
【3】：私有变量——设置NodeHandle nh("~")，（xxx/yyy）
## 【4】.参数重名
### --1.命令行实现
`rosrun turtlesim turtlesim_node _A:=100
### --2.launch文件实现
参见标签``<param>以及<rosparam>
### --3.编码实现
参考参数服务器内容
ros::param::set("/set_A",100); //全局,和命名空间以及节点名称无关
ros::param::set("set_B",100); //相对,参考命名空间
ros::param::set("~set_C",100); //私有,参考命名空间与节点名称

ros::NodeHandle nh;
nh.setParam("/nh_A",100); //全局,和命名空间以及节点名称无关
nh.setParam("nh_B",100); //相对,参考命名空间
ros::NodeHandle nh_private("~");
nh_private.setParam("nh_C",100);//私有,参考命名空间与节点名称


