# 边缘 AI/端侧 AI



将 AI 模型（量化裁剪后）部署到嵌入式硬件终端设备上，然后进行推理运算决策。相比云端 AI，边缘 AI 优势是可以离线，响应速度更快。





# OpenCV 库编译安装



OpenCV：一款基于 C++ 的计算机视觉库，开源免费跨平台。



> ROS/ROS2：Robot Operating System，机器人操作系统，Linux 上的一个用于机器人开发的第三方库。



OpenCV 基于 CMake 构建。



在 Linux 系统上部署 OpenCV 库：

1. sudo apt update
2. sudo apt upgrade -y
3. 安装所需工具和依赖：sudo apt install -y git g++ make cmake libgtk-3-dev libavcodec-dev libavformat-dev libswscale-dev
4. 获取 OpenCV 库的源码：git clone https://gitee.com/itmojun/opencv
5. cd opencv
6. mkdir build
7. cd build
8. cmake ..
9. make -j2
10. sudo make install



> cmake 配置文件为：CMakeLists.txt





# OpenCV 库的使用



常用类：

- Mat：Matrix，矩阵类，用于表示一帧图像或其他多行多列数据
- VideoCapture：视频捕获类，可以从 Camera 或视频文件采集图像帧



常用函数：

- imshow：image show，在指定窗口（通过窗口名指定）上显示一帧图像
- imwrite：image write，将一帧图像保存为图片文件
- imread：image read，从图片文件读取一帧图像数据
- 绘图函数：putText（绘制文本）、line（绘制线条）、rectangle（绘制矩形）、circle（绘制圆形）等
- waitKey：等待键盘按键，超时时间以 ms 为单位
- cvtColor：颜色空间转换，比如将彩色图转换为灰度图



颜色编码：RGB565、BGR、RGB 等。



> 音视频处理：FFmpeg 库



fps：frame per second，帧率。

分辨率





人脸检测(Face Detect)：在一帧图像中测出人脸区域



人脸识别(Face Recognition)：判断是谁的脸



AI 开发两步曲：

- 模型训练
- 模型推理



标准模型文件格式：ONNX