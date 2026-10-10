# Linux 系统高级编程技术







## 文件系统管理





> Linux 设计哲学：一切皆文件



Linux 系统中 7 种文件类型：

- 普通文件(Regular Flie)
- 文件夹(目录，Directory)
- 套接字文件(Socket)
- 符号链接(软连接，Symbolic Link)
- 管道(FIFO)
- 字符设备(Character Device)
- 块设备(Block Device)



Linux 系统调用(System Call)：Linux 系统提供的各种 API 函数。



> API：Application Program Interface，应用程序编程接口。





普通文件操作常用系统调用：

- open：打开文件
- create：打开文件(如果文件不存在就创建，存在清空，等效于 open 函数带上 O_WRONLY | O_CREAT | O_TRUNC 参数)
- read：读文件
- write：写文件
- close：关闭文件
- lseek：设置文件读/写位置指针
- umask：设置文件权限创建掩码
- unlink：删除文件
- stat/lstat：获取文件的属性信息(普通文件和文件夹都使用)，ls -l 命令内部就是调用该函数实现的。
- chmod：修改文件权限(普通文件和文件夹都使用)
- chown：修改文件所属用户和群组(普通文件和文件夹都使用)





文件夹操作常用系统调用：

- mkdir：创建文件夹
- rmdir：删除空文件夹
- opendir：打开文件夹
- readdir：读文件夹中的一个文件的信息
- closedir：关闭文件夹

标准 C 库在提供了一个 remove 函数，它能删除普通文件或空文件夹，它内部就是先判断目标文件的类型，然后调用 unlink 或 rmdir 函数。





> 标准 C 库函数内部都是调用系统函数功能实现的，如：fopen 函数在 Linux 系统上就是调用 read 函数实现的
>
> 标准 C 库函数可以跨平台，Linux 系统调用只能在 Linux 平台使用，不能跨平台





open 函数返回值的意义：如果打开文件成功，返回值为文件描述符(File Descriptor，非负整数)，用于标识被打开的文件，如果打开文件失败，返回值为 -1。



标准 C 库函数中时间处理相关函数：time、localtime等。