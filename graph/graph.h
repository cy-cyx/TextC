#ifndef GRAPH_H

#define GRAPH_H

#include "graph_base.h"
#include "queue.h"
#include "linkedlist.h"

/*
*��ʼ��
*/
void initGraph(Graph*);

/*
*��ӡ
*/
void printGraph(Graph*);

/*
* ���붥��
*/
void insertVer(Graph*,char);

/*
* ���뻡����Ȩ��
*/
void insertArc(Graph*,Arc*);

/*
* ������ȱ���(����)
*/
void dfs(Graph*);

/*
* ������ȱ���������
*/
void bfs(Graph*);

/*
* ����ķ�㷨����С��������  ʵ����ʹ�� ̰���㷨
*/
void prim(Graph*,char);

/*
* ��³˹�����㷨 ����С��������  ʵ����ʹ�� ̰���㷨
*/
void kruskal(Graph*);

#endif
