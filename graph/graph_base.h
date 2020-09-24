#include <iostream>

#ifndef GRAPH_BASE_H

#define GRAPH_BASE_H

#define blankVer ' '
#define Max 1000000
#define MAXVER 100  // 最大的顶点数 

/*
* 通过矩阵存图
*/
typedef struct {
	char vers[MAXVER];  // 放顶点
	int arc[MAXVER][MAXVER];  // 放度

	int vesNum,arcNum;
} Graph;

#endif
