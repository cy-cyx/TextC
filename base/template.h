/**
模板是泛型编程的基础
*/
#ifndef TEMPLATE_H

#define TEMPLATE_H

// typename 代表T为数据类型
template <typename T> T templateTypeFun (T a,T b) {
	return a > b ? a : b;
}

// class 代表是一个类
template <class C> C templateClassFun(C a) {
	return a;
}


#endif
