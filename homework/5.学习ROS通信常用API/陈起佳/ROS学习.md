
## vscode相关操作：

1. 调出终端：CTRL+~（调出系统终端为CTRL+ALT+T）
2. 编译：CTRL+Shift+B
3. 复制/粘贴：CTRL+Shift+C/V（终端的cv操作也是这样）

## ROS相关操作：

1. 运行前文件的配置：
	 - 在功能包下的  Cmakelists  中配置  `add_executable`  和  `target_link_libraries`
	 - 自定义msg话题通信的配置：
		 - 首先在功能包下添加  .msg  文件，自定义msg类型及名字
		 - 然后在  package.xml  中配置编译依赖（`<build_depend>message_generation</build_depend>`）和执行依赖（`<exec_depend>message_runtime</exec_depend>`）
		 - 然后在  Cmakelists  中的  find_package  中加入  message_generation；在  add_message_files  中将  .msg  文件改为自己定义的  .msg  文件；解注释  generate_messages；解注释  catkin_package  中的  CATKIN_DEPENDS  并在其后面添加  message_runtime
		- 在vscode的  c_cpp_properties.json  中的  includepath  下面添加  head  文件的路径（head文件在  /devel/include/包名  路径下）
2. 运行前终端的配置：
	- 先要roscore
	- 接着source一下（用  `echo "source ~/工作空间/devel/setup.bash" >> ~/.bashrc`  后可免去每次source的步骤）
	- 然后就能rosrun了
3. launch文件的配置：
	- 首先在功能包下添加  launch  文件夹
	- 然后在  launch  文件夹下添加  .launch  文件
	- 然后配置  launch  文件![[Pasted image 20230408231046.png]]
	- 最后用  roslaunch/rosmo  运行  launch  文件即可
4. 调出计算图：在运行文件后新开终端输入  rqt_graph  即可
5. 处理通信中第一条数据丢失：注册后，加入休眠 ros::Duration().sleep()，延迟第一条数据的发送

## 常用API

1. 初始化函数 init 
	- argc：存放了参数的个数（包括参数的名字）
	- argv：是一个存放了参数的值的数组（包括参数的名字）
	- name：自定义节点名称（具有唯一性）
	- options：可对节点的启动做相应的设置（如   `ros::init_options::AnonymousName`   可令节点能够重复启动，其原理是在节点名后加上随机数，避免重名）
2. 句柄函数 NodeHandle 
	- advertise函数：
		- 模板：即<>里的内容，是待发布消息的消息类型
		- 参数：
			- 话题名称
			- 队列长度：即最大缓存的数据量，缓存高于队列长度的数据将被丢弃
			- latch：
				- 作用：是布尔值，默认为 false ，若设置为 true ，则可以保存发布的最后一条数据，并在新的订阅对象链接到时，将这条信息发布给它
				- 设置：直接写 true 或 false ，不用写 latch= 之类的
				- 使用场景：当发布静态的、不变的信息时（如：小车导航中发布静态地图时）可将 latch 设置为 true ，从而提高效率
3. 回旋函数 spin / spinOnce
	- spinOnce ：常用于循环体中；该函数只会回调一次回调函数，也就是在其后面的代码能够执行到
	- spin ：执行到 spin 语句时，会进入回调函数，并循环地执行回调函数，所以其后面的代码不会执行到
4. 时间
	- 注意：在调用时间相关函数之前必须创建ros句柄，因为NodeHandle中能实现初始化时间的操作，若不创建则会导致时间初始化失败
	- 参考系：1970年1月1日00:00:00  （中国是东八区，故初始时间是8点）
	- 时刻：
		- 获取当前时刻：`ros::Time::now()`  ，返回值为 `ros::Time` 类型
		- 将获取的时刻转为以秒为单位： `name.toSec() / name.sec`  （前者是浮点数，后者是整型）
		- 设置时刻：`ros::Time name(整型秒，整型纳秒)`  /  `ros::Time name(浮点数)`
	- 持续时间： `ros::Duration name(整型秒，整型纳秒)`  /  `ros::Duration name(浮点数)`
	- 时间运算：
		- 时刻与持续时间：可以加减（直接加减就行）
		- 持续时间与持续时间：可以加减（同上）
		- 时刻与时刻：可以减，不可以加（减的时候返回的是持续时间）
	- 运行频率：
		- rate 实现：  `ros::Rate name(频率)`
		- 定时器实现：
			-  实现函数： `ros::Timer name = nh.createTimer(ros::Duration(持续时间),callback)`
			- 第一个参数为持续的时间，单位为s
			- 第二个参数为回调函数： `void callback(const ros::TimerEvent& event)`
			- 可设置第三个参数 onshot ，默认为 false ，设为 true 时指只执行一次回调函数（直接写 true 或 false ）
			- 可设置第四个参数 autostart ，默认为 true ，设为 false 时指取消定时器自动启动（也是直接写 true 或 false）（设为 false 时若要启动，则需要利用 `name.start()`  函数来启动）
			- 注意：使用定时器也需要 spin 一下
5. 节点生命周期
	- 判断节点存活状态： `ros::ok()`
	- 关闭节点： `ros::shutdown()`
6. 日志
	- 调试信息： `ROS_DEBUG()`  （一般不会输出在控制台）
	- 一般信息： `ROS_INFO()` （白色）
	- 警告信息： `ROS_WARN()` （黄色）
	- 错误信息： `ROS_ERROR()` （红色）
	- 严重错误信息： `ROS_FATAL()` （红色）