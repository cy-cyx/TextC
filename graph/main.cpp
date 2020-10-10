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

	// a-> c 7
	arc->adv = 7;
	arc->quit = 'a';
	arc->enter = 'c';
	insertArc(graph,arc);

	// a-> d  10
	arc->adv = 10;
	arc->quit = 'a';
	arc->enter = 'd';
	insertArc(graph,arc);

	// c-> d  1
	arc->adv = 1;
	arc->quit = 'c';
	arc->enter = 'd';
	insertArc(graph,arc);

	// b-> a 12
	arc->adv = 12;
	arc->quit = 'b';
	arc->enter = 'a';
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
//	Node* n = new Node();
//	n->c = 'a';
//	n->next = NODE_NULL;
//
//	q->enqueue(n);
//
//	Node* n1 = new Node();
//	n1->c = 'c';
//	n1->next = NODE_NULL;
//
//	q->enqueue(n1);
//
//	Node* on = q->poll();
//	std::cout << on->c << std::endl;
//	delete on;
//
//	Node* on1 = q->poll();
//	std::cout << on1->c << std::endl;
//	delete on1;

	// 普里姆算法
	prim(graph,'a');

	free(arc);
	free(graph);
	return 0;
}
