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





> APUE：Unix 环境高级编程









## 库(Library)



库的意义：

- 二进制级别代码复用，保护与源代码
- 方便更新维护



库分为两种：

- 静态库(Static Library)：静态链接库，采用静态链接方式。在 Linux 系统中，静态库文件后缀名通常为.a；在 Windows 系统中，静态库文件的后缀名为.lib
- 共享库(Shared Library)：动态链接库(Dynamic Link Library,DLL)，采用动态链接方式。在 Linux 系统中，动态库文件后缀名通常为.so；在 Windows 系统中，静态库文件的后缀名为.dll



在 Linux 系统中，静态库和共享库的文件名都以 lib 作为前缀，如：libmath.a、libpng.so 等。另外，共享库还支持在后缀名后面附上库的版本号，比如libmd5.so.1.2.3、libmath.so.2 等。



库可以对外导出函数和全局变量。



**要求熟练掌握如何制作静态库和共享库、如何调用静态库和共享库。**







### 静态库(Static Library)





**制作静态库**



步骤：

1. 将相关源文件(.c)编译为目标文件(.o)，如gcc  -c  dome.c  1.c
2. 使用 ar 命令将上一步得到的所有目标文件打包为静态库文件，如 ar  cr  libdome.a  dome.o  1.o



> 静态库本质就是一个包含若干个目标文件(.0)的压缩包文件。





**调用静态库**



在链接阶段链接依赖的静态库即可

gcc main.c  -L./  -L/  -ldome





gcc 常用参数：

- -l 指定要连接的库的文件名(省略前缀 lib 和后缀名)
- -L 指定库文件搜索路径(gcc 默认只搜索系统库文件目录 /usr/lib)