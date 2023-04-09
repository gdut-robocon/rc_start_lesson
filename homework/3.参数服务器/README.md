题目：编写一个ROS节点，读取一个yaml文件中的参数，并将其发布到一个名为“yaml_param”的话题上。同时，创建一个订阅者节点，接收“yaml_param”话题的消息，并将其打印到终端上。

具体要求：

1. 发布者节点名称为“yaml_publisher”，订阅者节点名称为“yaml_subscriber”。

2. 发布者节点读取一个名为“my_param”的参数，该参数从一个名为“my_yaml.yaml”的yaml文件中读取。该参数应该是一个字符串类型。

3. 发布者节点将参数值发布到一个名为“yaml_param”的话题上，消息类型为std_msgs::String。

4. 订阅者节点订阅“yaml_param”话题，接收发布者发布的消息，并将其打印到终端上。
