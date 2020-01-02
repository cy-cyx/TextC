/*
结构体：
1、C与C++ 不同之处就是定义结构体时：C++ 可以不加typeder 且C++ 的结构体可以包含方法函数
例子：
typeder struct 结构名
{
}别名；

2、定义在头文件或者.cpp文件的区别主要看作用域的大小，避免过多的暴露
*/
#ifndef STRUCT_H

#define STRUCT_H

typedef struct structDome {
	int a;
	int add(int a,int b) {
		return a + b;
	}
} sDome;

#endif
