/**
ģ���Ƿ��ͱ�̵Ļ���
*/
#ifndef TEMPLATE_H

#define TEMPLATE_H

// typename ����TΪ��������
template <typename T> T templateTypeFun (T a,T b) {
	return a > b ? a : b;
}

// class ������һ����
template <class C> C templateClassFun(C a) {
	return a;
}


#endif
