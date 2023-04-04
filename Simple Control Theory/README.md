# 简单入门控制相关理论

在本次项目课中同学们应掌握，PID控制理论，底盘解算的知识。

PID控制算法：https://zhuanlan.zhihu.com/p/39573490https://zhuanlan.zhihu.com/p/39573490





我们这些在ROS中都集成在PID_toolbox里面，但是大家还是要知道这些是如何工作的，能够将一个复杂的控制问题转换为数学问题

三向全向轮底盘解算(包括机器人坐标系和世界坐标系)：

https://blog.csdn.net/weixin_41995979/article/details/81704172

伪代码如下：

```c
//三轮全向轮底盘<mm/s>
void World_3wheels_onmi(float Vx,float Vy,float W,float theta)
{
	float A_wheel_target_RPM,B_wheel_target_RPM,C_wheel_target_RPM;
	theta = theta* PI / 180.0f;
	A_wheel_target_RPM = Vel2Pulse(-( -cos(theta) * Vx -sin(theta) * Vy + Robot_R*W));
	B_wheel_target_RPM = Vel2Pulse(-(+sin(theta+PI/6.0f) * Vx - cos(theta+PI/6.0f) * Vy + Robot_R*W));
	C_wheel_target_RPM = Vel2Pulse(-(+cos(theta+PI/3.0f) * Vx + sin(theta+PI/3.0f) * Vy + Robot_R*W));
	//remember to change ID when you use!
	VelCrl(&hcan1,1,A_wheel_target_RPM);
	VelCrl(&hcan1,2,B_wheel_target_RPM);
	VelCrl(&hcan1,3,C_wheel_target_RPM);
}
```

所有的底盘解算这些都集成在底盘控制器，一样的，了解这些知识很有必要
