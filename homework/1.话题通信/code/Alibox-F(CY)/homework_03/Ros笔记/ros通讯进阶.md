# 常用API详解

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
**tips:只有执行到spin才会调用callback**

## 4.时间相关API

### --1.ros::time::now()
获取当前时刻（相对于0时区1970年1月一日00：00：00的秒数）
### --2.ros::time var(int/float)
设置指定时刻
### --3.

ROS_INFO("%.2f",var.Tosec())
ROS_INFO("%.d",var.sec())
创建nh才可使用（尽管没有调用）