#include <iostream>

#ifndef GRAPH_BASE_H

#define GRAPH_BASE_H

#define blankVer ' '
#define Max 1000000
#define MAXVER 100  // ���Ķ����� 

/*
* ͨ�������ͼ
*/
typedef struct {
	char vers[MAXVER];  // �Ŷ���
	int arc[MAXVER][MAXVER];  // �Ŷ�

	int vesNum,arcNum;
} Graph;

#endif
