#include <iostream>
#include <malloc.h>
#include "graph.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Graph* graph = (Graph*)malloc(sizeof(Graph));

	initGraph(graph);

	// 顶底a,b,c,d
	insertVer(graph,'a');
	insertVer(graph,'b');
	insertVer(graph,'c');
	insertVer(graph,'d');

	// 弧
	Arc* arc = (Arc*)malloc(sizeof(Arc));

	// a-> b 1
	arc->adv = 1;
	arc->quit = 'a';
	arc->enter = 'b';
	insertArc(graph,arc);

	// c-> d  2
	arc->adv = 2;
	arc->quit = 'c';
	arc->enter = 'd';
	insertArc(graph,arc);

	// a-> c 3
	arc->adv = 3;
	arc->quit = 'a';
	arc->enter = 'c';
	insertArc(graph,arc);

	// b-> d 4
	arc->adv = 4;
	arc->quit = 'b';
	arc->enter = 'd';
	insertArc(graph,arc);

	// 深度遍历
	dfs(graph);

	std::cout << std::endl;

	// 广度遍历
	bfs(graph);

	std::cout << std::endl;

	// 打印
	printGraph(graph);

	std::cout << std::endl;

	// 测试队列
//	Queue* q = new Queue;
//
//	// 插入
//	QueueNode* n = new QueueNode();
//	n->c = 'a';
//	n->next = NODE_NULL;
//
//	q->enqueue(n);
//
//	QueueNode* n1 = new QueueNode();
//	n1->c = 'c';
//	n1->next = NODE_NULL;
//
//	q->enqueue(n1);
//
//	QueueNode* on = q->poll();
//	std::cout << on->c << std::endl;
//	delete on;
//
//	QueueNode* on1 = q->poll();
//	std::cout << on1->c << std::endl;
//	delete on1;

	// 测试列表
//	LinkedList* list = new LinkedList();
//
//	// 1
//	LinkedListNode* n1 = new LinkedListNode();
//	n1->c = '1';
//
//	LinkedListNode* n2 = new LinkedListNode();
//	n2->c = '2';
//
//	LinkedListNode* n3 = new LinkedListNode();
//	n2->c = '3';
//
//	list->addRoot(n1);
//	list->addRoot(n2);
//	list->addRoot(n3);
//	
//	list->deleteRoot(n2);


	// 普里姆算法
	prim(graph,'a');

	std::cout<< std::endl;

	// 克里鲁斯卡算法
	kruskal(graph);

	free(arc);
	free(graph);
	return 0;
}
