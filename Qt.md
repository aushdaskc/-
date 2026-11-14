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

QPlainTextEdit
QDateEdit
QComboBox



输入合法性校验



调试输出：qDebug

屏幕坐标系







## 对话框(Dialog)



QDialog



对话框分为两种：

- 模态对话框(Model Dialog)：弹出后会一直阻塞其父窗口，直到用户关闭该窗口
- 非模态对话框(Modeless Dialog)：弹出后不会阻塞其父窗口，用户依然可以在父窗口上操作





### 通用对话框(Common Dialog)



实现一些通用功能的对话框窗口，常用的有：

- 消息框(QMessageBox)
- 打开文件/保存文件对话框(QFileDialg)
- 选择颜色对话框(QColorDialg)
- 选择字体对话框(QFontDialg)







## 常用文本数据格式





**CSV**

1001,张三,男,4.5



**JSON**

[{

"sno":1001

"name":"张三"

"sex":"男"

"sight":4.5

},



{

"sno":1002

"name":"李四"

"sex":"男"

"sight":4.6

}]



JSON格式解析库：cJSON



**XML**

```xml	
<xml charset="UTF-8">
	<student id="1">
        <sno>1001</sno>
        <name>张三</name>
        <sex>男</sex>
        <sight>4.5</sight>
    </student>
</xml>
```



XML 解析库：tinyxml







纯代码方式实现 UI



Qt Designer：Qt 设计器



UIC：UI 编译器，负责将 UI 文件（就是一个 XML 文件）编译为 C++ 代码（在预处理阶段）。



对象树(Object Tree)机制



信号和槽的连接方式：

- 直接连接(Qt::DirectConnection)：立即在发射信号的线程中调用槽函数，适用于同一个线程中的对象。
- 队列连接(Qt::QueuedConnection)：槽函数将在接收者对象所在的线程中执行，适用于不同线程中的对象。
- 自动连接(Qt::AutoConnection)：如果发射者和接收者属于同一个线程，就是用直接连接，否则使用队列连接。
- 阻塞队列连接(Qt::BlockingQueuedConnection)：发射信号后阻塞等待槽函数执行结束。
- 唯一连接(Qt::UniqueConnection)：需要和上面四种连接方式配合使用，限制相同连接只有一个，重复连接会失败。



布局管理器(Layout)：

- 水平布局管理器(QHBoxLayout)
- 垂直布局管理器(QVBoxLayout)
- 网格布局管理器(QVGridLayout)
- 表单布局管理器(QFormLayout)
- 栈布局管理器(QStackedLayout)





多窗口交互：

- 模态对话框
- 非模态对话框



掌握不同窗口之间的数据传输。



explicit 关键字：C++ 关键字，用于修饰构造函数，表示该函数必须显示使用，不能用于自动类型转换。







## 线程(Thread)



UI Thread：负责用户界面处理(事件循环)，千万不能执行耗时任务，否则窗口会失去响应，严重影响用户体验。

Worker Thread：工作者线程，不负责界面处理，用于执行耗时任务，如大量数据排序、大文件拷贝、通信等。



主线程就是：UI Thread。



Qt 库中线程实现方法：

- 子类化  QThread，重写 run 方法
- moveToThread
- QtConcurrent



核心要点：

- Worker Thread 不要直接操作 UI，因为 UI 对象是非线程安全的，通过信号槽实现
- 线程参数传递方法





## 自定义信号



信号就是一个没有实现的方法，支持参数，使用 emit 宏发射信号。





## 通信



基于 TCP 通信：QTcpServer、QTcpSocket
基于 UDP 通信：QUdpSocket