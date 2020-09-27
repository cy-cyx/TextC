#ifndef GRAPH_BASE_H

#define GRAPH_BASE_H

#include <iostream>
#define blankVer ' '
#define Max 1000000
#define MAXVER 100  // ���Ķ����� 

/*
* ͨ�������ͼ
*/
typedef struct {
	char vers[MAXVER];  // �Ŷ���
	int arc[MAXVER][MAXVER];  // �Ż�

	int vesNum,arcNum;
} Graph;

/*
* ��
*/
typedef struct {
	char enter;  // ���
	char quit;   // ����
	int adv;     // Ȩ
} Arc;



#endif
