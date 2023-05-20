#liinux 

# 将浏览器下载软件显示在应用程序界面

### 1.如果有xxx.dep格式的直接下载双击打开即可安装（优先）
### 2.如果下载的为tar.gz/tar.xz 形式的源码包（github上的一些软件）
#### 有安装说明
解压到合适的位置
转到文件夹输入
```
$ ls
```
在展示的文件中找到install或者readme等说明性文件
按照文件提示进行安装

#### 没有说明性文件
手动添加桌面文件
跳转到计算机/opt/applications 将解压后的软件包移植过来
获取root权限：在计算机文件夹双击root文件夹，输入密码即可在当前窗口获取root权限
新建xxx.desktop 文件：在usr/share/applications  中新建
```
[Desktop Entry]
Encoding=UTF-8                    ##非必要
Version=1.0                       ##非必要
Name=Clash for Linux              ##显示在桌面的名字
GenericName=Clash for Linux       ##非必要
Comment=clash                     ##非必要
Exec=/opt/Clash/cfw  %f           ##此处填写执行文件路径（一般是.sh文件）
Icon=/opt/Clash/apps/clash.ico    ##此处填写应用图标路径
Terminal=false                    ##必要，根据需要填写false or true
Type=Application                  ##必要，一般填写Application
Categories=Development;IDE        ##必要，填写应用种类（开发环境集成....）
```

PS:1.不要打多余空格
    2.%f一定要加

在主文件夹里打开隐藏文件（按ctrl+h显示）.local/share/applications,复制一份xxx.desktop
最后打开终端,输入
```
sudo update-desktop-database ~/.local/share/applications
```
重启计算机
将xxx.desktop文件复制到桌面右键选择允许运行即可运行

PS：后来发现删除本地的.desktop文件可以正常运行，不删除会在应用程序界面显示两个相同的应用图标