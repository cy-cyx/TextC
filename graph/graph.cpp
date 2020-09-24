#include "graph.h"


void initGraph(Graph* graph) {

	// 全部置初始化状态
	graph->vesNum = 0;
	graph->arcNum = 0;

	// 将顶点置 ' '
	for(int i = 0; i < MAXVER; i++) {
		graph->vers[i] = blankVer;
	}

	// 将度 置为无穷
	for(int i = 0; i < MAXVER; i++) {
		for(int ii = 0; ii < MAXVER; ii++) {
			graph->arc[i][ii] = Max;
		}
	}

}

void printGraph(Graph* graph) {

	std::cout << "打印图开始______" << std::endl;

	std::cout << "打印顶点:";
	for(int i = 0; i < graph->vesNum; i++) {
		std::cout << graph->vers[i] << " ";
	}
	std::cout << std::endl;

	for(int i = 0; i < graph->vesNum; i++) {

		for(int ii = 0; ii < graph->vesNum; ii++) {
			std::cout<< "(" <<graph->arc[i][ii] << ")";
		}
		std::cout << std::endl;
	}

	std::cout << "打印图结束______" << std::endl;
}

void insertVer(Graph* graph,char ver) {

	// 不给重复插入相同的顶点
	for(int i = 0; i < graph->vesNum; i++) {
		if(graph->vers[i] == ver) {
			return;
		}
	}

	// 插入顶点数组
	graph->vesNum ++;
	graph->vers[graph->vesNum - 1] = ver;
}
