#ifndef GRAPH_H

#define GRAPH_H

#include "graph_base.h"
#include "queue.h"

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
* 深度优先遍历(无向)
*/
void dfs(Graph*);

/*
* 广度优先遍历（无向）
*/
void bfs(Graph*);

#endif
