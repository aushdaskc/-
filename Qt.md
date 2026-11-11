# Qt





## Qt 简介



Qt 是一个 C++ 开发库，主要用于 GUI 开发，开源免费，功能强大。



> GUI：图形化界面
>
> CUI：字符化界面



Qt 库：C++ 第三方库

Qt Cretor：C++ IDE，默认已经配置好了 Qt 库。



Qt 跨平台：

- Qt for Linux
- Qt for Windows
- Qt for Mac
- Qt for Android
- Qt for iOS
- Qt for MCU





## Hello Qt！ 





两种 Qt 开发方式：

- 传统 Qt Widgets 开发
- Qt Quick/QML 开发



Qt 库中所有类和函数都是以 Q/q 开头命名，采用驼峰式命名风格。



Widget：窗口组件，比如：按钮、输入框、下拉列表框、进度条、滑块等。



窗口界面的两种实现方式：

- 可视化设计方式：拖拽各种 Widget ，所见即所得，简单直观，无需写代码，适合固定不变的界面设计。
- 纯代码方式：灵活，不太直观，适合动态变化的界面设计。



CUI 程序：流程驱动
GUI 程序：事件驱动



Qt 程序执行流程：

1. 创建应用程序类(QApplication)的对象
2. 创建窗口类对象
3. 调用窗口对象的 show 方法，此时窗口就显示出来了
4. 事件循环(Event Loop)：不断检测窗口上发生的事件并进行相应处理，如果检测到退出事件，事件循环就会结束



窗口(Window)：屏幕上的一块矩形显示区域，用于和用户交互。



信号和槽机制(Signal-Slot)：用于实现对象之间通信，Qt 核心机制之一。将对象 A 的某个信号与对象 B 的某个槽函数连接起来，后面任何时刻只要对象 A 发射该信号，对象 B 的对应槽函数就会被自动调用一次，以实现对信号的响应处理。



槽函数(Slot)：就是一个方法。



QObject：Qt 库中的根类，大部分类都直接或间接继承于它。





## 常用 Widgets 用法





QPushButton：普通按钮
QRadioButton：单选按钮
QCheckBox：复选框
QLabel：标签，用于显示文本或图像
QLineEdit：单行编辑框，用于输入一行文本



调试输出：qDebug

屏幕坐标系