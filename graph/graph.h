#include "graph_base.h"

#ifndef GRAPH_H

#define GRAPH_H

/*
*初始化
*/
void initGraph(Graph*);

/*
*打印
*/
void printGraph(Graph*);

/*
* 插入顶点
*/
void insertVer(Graph*,char);

/*
* 插入弧（带权）
*/
void insertArc(Graph*,Arc*);

/*
* 深度优先遍历
*/
void dfs(Graph*);

#endif
