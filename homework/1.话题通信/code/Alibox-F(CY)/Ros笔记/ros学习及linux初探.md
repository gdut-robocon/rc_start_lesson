#liinux #ros

# linux系统下载及安装


## windows下ubuntu双系统安装

### 流程:

参考视频
[ Windows 和 Ubuntu 双系统的安装和卸载](https://www.bilibili.com/video/BV1554y1n7zv?p=3&vd_source=c00c89594eed44d90479a133f7482387)

概要：
1.ubuntu官网或其他镜像站下载镜像文件
[ubuntu官网](https://cn.ubuntu.com/download/alternative-downloads)[阿里云开源镜像站](http://mirrors.aliyun.com/ubuntu-releases/)
下载desktop版的镜像文件（iso）
2.下载镜像文件写入工具
[win32diskimager](https://sourceforge.net/projects/win32diskimager/)
3.准备U盘做为安装盘
4.查看磁盘分区
5.创建磁盘分区
6.进入bios界面安装

**Tips：若无法进入bios界面，还可以尝试直接用windows系统-恢复-高级启动-立即重启，从u盘启动即可**

# 配置ROS环境

强烈推荐鱼香ros一键安装
[fishros官网](http://fishros.com/#/fish_home)

创建工作空间
 1.命令行创建 
# 配置环境变量
## 1.局部配置
source ./devel/setup.bash
退出窗口即失效
## 2.全局配置
在主目录下:
<kbd>ctrl</kbd> + <kbd>h</kbd>
点击.bashrc文件
在末尾添加source ./路径/setup.bash 即可



