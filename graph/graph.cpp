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

void insertArc(Graph* graph,Arc* arc) {
	int enterArc; // 竖
	int quitArc;  // 横

	// 入度
	for(int i = 0; i < graph->vesNum; i++) {

		if(graph->vers[i] == arc->enter) {

			enterArc = i;

			break;
		}

		if(i == graph->vesNum - 1) {
			return;
		}
	}

	// 出度
	for(int i = 0; i < graph->vesNum; i++) {

		if(graph->vers[i] == arc->quit) {

			quitArc = i;

			break;
		}

		if(i == graph->vesNum - 1) {
			return;
		}
	}

	graph->arc[quitArc][enterArc]  = arc->adv;
}

/*
* 寻找是否是遍历过的顶点
*/
bool findFineVer(char target,char* fineVers,int* fineVersIndex) {
	for(int i = 0; i < *fineVersIndex; i++) {

		if(fineVers[i] == target) {
			return true;
		}

	}
	return false;
}

void dfsInner(Graph* graph,char lastTarget,char target,char* fineVers,int* fineVersIndex) {

	std::cout << "上一个连接顶点" << lastTarget << "--遍历顶点:" << target << std::endl;

	fineVers[*fineVersIndex]= target;
	*fineVersIndex = *fineVersIndex + 1;


	int verIndex = 0;

	// 通过入度和出度 找它fineVersIndex相关的弧

	// 找到它在顶点数组中的位置
	for(int i = 0; i < graph->vesNum; i++) {
		if(graph->vers[i] == target) {
			verIndex = i;
			break;
		}
	}

	// 入度
	for(int i = 0; i < graph->vesNum; i++) {

		if(graph->arc[i][verIndex] != Max) {

			char nextVer = graph->vers[i];
			if(!findFineVer(nextVer,fineVers,fineVersIndex)) {
				dfsInner(graph,target,nextVer,fineVers,fineVersIndex);
			}
		}
	}

	// 出度
	for(int i = 0; i < graph->vesNum; i++) {

		if(graph->arc[verIndex][i] != Max) {

			char nextVer = graph->vers[i];
			if(!findFineVer(nextVer,fineVers,fineVersIndex)) {
				dfsInner(graph,target,nextVer,fineVers,fineVersIndex);
			}
		}
	}
}

void dfs(Graph* graph) {

	std::cout << "开始深度遍历______" << std::endl;

	// 存已找到的顶点
	char* fineVers = (char*)malloc(sizeof(char) * graph->vesNum);
	// 找到了几个
	int fineVersIndex = 0;

	// 开始遍历
	dfsInner(graph,' ',graph->vers[0],fineVers,&fineVersIndex);

	std::cout << "深度遍历结束______" << std::endl;
}





