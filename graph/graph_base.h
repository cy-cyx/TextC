#ifndef GRAPH_BASE_H

#define GRAPH_BASE_H

#include <iostream>
#define blankVer ' '
#define Max 1000000
#define MAXVER 100  // 最大的顶点数 

/*
* 通过矩阵存图
*/
typedef struct {
	char vers[MAXVER];  // 放顶点
	int arc[MAXVER][MAXVER];  // 放弧

	int vesNum,arcNum;
} Graph;

/*
* 弧
*/
typedef struct {
	char enter;  // 入度
	char quit;   // 出度
	int adv;     // 权
} Arc;



#endif
