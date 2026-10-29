# 项目选题





##  物联网云平台



核心功能：设备接入、设备管理、远程监控、OTA等





## 边缘网关



建议使用 Linux 开发板（比如 RK3568 等）

一侧通过 RS232、RS485、CAN、USB、Ethernet 等接口连接各种设备，采集数据或执行控制，另一侧通过 Ethernet/WiFi/4G/5G 连接互联网，可以将采集到的所有数据融合处理传送到服务器，并执行服务器下发的控制指令。







## 高性能 Web 服务器（基于 epoll 模型）







## 即时通讯软件







## 文件分发系统









## 项目版本管理



常用版本管理根据：

- git：分布式
- svn：集中式



git 的两种用法：

- git命令
- IDE 内部集成



```shell	
git config --global user.name "1234"
git config --global user.email "123456y"
```





常用命令：

- git init：创建一个本地 git 仓库
- git add：将工作区中的文件添加到暂存区
- git commit：将暂存区中的所有文件提交到本地 git 仓库，一定要指定详细的日志
- git status：查看状态
- git log：查看提交日志记录
- git reflog：查看所有版本信息
- git reset --hard 目标版本：回滚
- git remote add：添加远程仓库
- git push：将本地仓库推送到远程仓库



> Repository：仓库



主线版本、分支版本



github/gitee：远程 git 仓库托管平台(git 服务器)



自己搭建 git 服务器







## Make 和 CMake



自动化构建(Build)工具



Make 会读取项目文件夹中的 Makefile 文件，并根据该文件中的配置规则编译项目。



Makefile 是由若干条规则构成的，每条规则的格式如下：

```makefile
Target:Dependency
	Commandl
	Command2
```



cmake 用于生成 Makefile 文件(根据 CMakeList.txt 配置文件生成 Makefile 文件)