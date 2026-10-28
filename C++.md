# C++ 语言





## C++ 简介



C++ 于 1983 年诞生于美国贝尔实验室。

C++ 是一门功能强大的面向对象的高级编程语言。

C++ 无所不能，主要用于大规模复杂软件系统、高性能服务器、大型端游和手游、工控软件、嵌入式软件等。

C++ 继承了 C 的几乎一切语法特性，并新增了一些重要的语法特性，如引用、函数重载、模板、面向对象编程(类和对象)、RTTI等。C++ 是 C 的增强版本，带类的 C 语言。



面向过程编程思想：将一个实际问题拆分成若干个处理步骤，每个步骤用一个或多个函数实现，然后将这些函数按顺序依次调用起来就能解决目标文件。



面向对象编程思想(OOP,Object Oriented Program)：将一个实际问题拆分成若干个对象，每个对象都有自己的属性和方法，对象之间互相通信和交互就能实现各种功能。



对象(Object)：一个实际事物。







## C++ 基础



C++ 源文件的后缀名通常为.cpp或.cc



C++ 编译器：g++



C++ 标准库中的头文件没有后缀名

C++标准库提供了一套和标准C库功能一样的头文件，但文件名不同，没有后缀名，并且前缀为c，比如：stdio.h 对应的是 cstdio，string.h对应的是 cstring，time.h 对应的是 ctime 等。



> gcc 也可以用于编译 C++ 代码，需要带上 -lstdc++ 参数





## 数据类型



C++ 新增 bool 类型、引用类型、类类型。



bool：布尔类型，1 Byte，两个常量：true 和 false



C++ 风格强制类型转换：type(exp)



引用类型(Reference)：就是一个别名，封装了指针，比指针更简单好用，可以在大部分场合取代指针。

在声明或定义引用时必须同时初始化，后面不能再改变引用关系。



```C++
int a = 3;
int& b = a;   // 声明引用 b，它指向 a，就是变量 a 的别名

b++;
a++;
```





C 语言只支持值传递，C++ 不仅支持值传递，还支持引用传递。

```C++
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```





常引用(Const Reference)：常量的引用，即该引用指向的是一个常量(在该引用心中是常量，不要求它是真正的常量)，通过常引用不能对它指向的数据进行写操作。

在使用引用作为函数的参数时，如果函数内部无需对该引用进行写操作，强烈建议定义为常引用！

```C++
int a = 3;
int& b = a;
const int& c = a;

c++;   // error
c = a; // error
```







## 函数



函数重载(Founction Overload)：函数名相同，但形参的个数或类型不同(即形参列表不同)



默认参数(Default Argument)：函数参数可以指定默认值，简化函数调用。

注意：所有默认参数必须写在最右边。

```C++
long pow(long, long = 2); // 声明时指定默认参数，定义时就不要再指定了
long pow(long x, long y)
{
    long r = 1;
    
    while(y--) r *= x;
    
    return r;
}
```







## 模板(Template)



借助模板可以优雅轻松实现 GP。



> GP：泛型编程



模板分为两种：

- 函数模板(Function Template)
- 类模板(Class Template)



C++ 编译器会根据实际定义情况自动推导出具体的函数





函数模板：

```C++
#include <iostream>
#include <string>
#include <cstring>  // string.h

using namespace std;


// 定义函数模板
template <typename T>  // 模板声明，T 称为模板类型参数，使用 typename 或 class 关键字声明模板类型参数，可以声明多个
T sum(T a, T b)
{
  return a + b;
}


// 定义函数模板
template <typename T>  // 模板声明
void bubble_sort(T* data, size_t n)  // 升序
{
  int i, j;
  T tmp;
  
  for(i = 0; i < n - 1; i++)
  {
    for(j = 0; j < n - i - 1; j++)
    {
      if(data[j] > data[j + 1])
      {
        tmp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = tmp;
      }
    }
  }
}


int main()
{
  string s1 = "junge", s2 = " yyds!", s3;
  
  cout << sum(1, 2) << endl;
  cout << sum(1.1, 2.2) << endl;
  cout << sum('a', '\n') << endl;
  cout << sum(1.1F, 2.2F) << endl;

  s3 = sum(s1, s2);
  cout << s3 << endl;  // junge yyds!

  cout << sum(1, 1.1) << endl;  // error

  cout << sum<float>(1, 1.1) << endl;  // ok

  int a1[] = {5, 3, 4, 1, 2};
  double a2[] = {3.3, 1.1, 2.2};
  char a3[] = "junge yyds!";

  sort(a1, 5);
  sort(a2, 3);
  sort(a3, strlen(a3));

  // 更明确、更推荐的写法
  //sort<int>(a1, 5);
  //sort<double>(a2, 3);
  //sort<char>(a3, strlen(a3));

  int i;

  for(i = 0; i < 5; i++)
  {
    cout << a1[i] << ' ';
  }

  cout << endl;

  for(i = 0; i < 3; i++)
  {
    cout << a2[i] << ' ';
  }
  
  cout << endl;

  cout << a3 << endl;
  
  return 0;
}
```

