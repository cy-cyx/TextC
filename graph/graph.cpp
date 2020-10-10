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

	graph->arcNum ++;
	graph->arc[quitArc][enterArc]  = arc->adv;
}

/*
* 寻找是否是遍历过的顶点
*/
bool findFineVer(char target,char* fineVers,int* fineVersSum) {
	for(int i = 0; i < *fineVersSum; i++) {

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



void bfs(Graph* graph) {

	std::cout << "开始广度遍历______" << std::endl;

	// 存已找到的顶点
	char* fineVers = (char*)malloc(sizeof(char) * graph->vesNum);
	// 找到了几个
	int fineVersIndex = 0;

	// 使用队列遍历广度
	Queue* q = new Queue();

	// 塞入第一个点
	Node* fristNode = new Node();
	fristNode->last = ' ';
	fristNode->c = graph->vers[0];
	fristNode->next = NODE_NULL;
	q->enqueue(fristNode);

	Node* temp = NODE_NULL;

	temp = q->poll();
	while(temp != NODE_NULL) {

		if(findFineVer(temp->c,fineVers,&fineVersIndex)) {
			delete temp;
			temp = q->poll();
			continue;
		}

		std::cout<< "根："<< temp->last << "顶点：" << temp->c << std::endl;

		// 塞进已找到的组
		fineVers[fineVersIndex]= temp->c;
		fineVersIndex = fineVersIndex + 1;

		// 找到在顶点数组中的位置
		int verIndex = 0;
		for(int i = 0; i < graph->vesNum; i++) {
			if(graph->vers[i] == temp->c) {
				verIndex = i;
				break;
			}
		}

		// 从入度找
		for(int i = 0; i < graph->vesNum; i++) {
			if(graph->arc[i][verIndex] != Max) {

				char nextVer = graph->vers[i];
				if(!findFineVer(nextVer,fineVers,&fineVersIndex)) {
					Node* n = new Node();
					n->last = temp->c;
					n->c = nextVer;
					n->next = NODE_NULL;
					q->enqueue(n);
				}
			}
		}

		// 出度
		for(int i = 0; i < graph->vesNum; i++) {

			if(graph->arc[verIndex][i] != Max) {

				char nextVer = graph->vers[i];
				if(!findFineVer(nextVer,fineVers,&fineVersIndex)) {
					Node* n = new Node();
					n->last = temp->c;
					n->c = nextVer;
					n->next = NODE_NULL;
					q->enqueue(n);
				}
			}
		}

		delete temp;
		temp = q->poll();
	}

	delete q;

	std::cout << "结束广度遍历______" << std::endl;

}

/*
* 值在数组中的位置
*/
int findVesIndex(char target,char* vers,int* versSum) {
	for(int i = 0; i < *versSum; i++) {
		if(vers[i] == target) {
			return i;
		}
	}
	return 0;
}

void prim(Graph* graph,char root) {
	std::cout << "开始生成最小树(普里姆算法)" << std::endl;

	std::cout << "根为：" << root << std::endl;

	int consSum = 0;
	// 放已经连接的顶点
	char* cons = (char*)malloc(sizeof(char) * graph->vesNum);

	cons[consSum] = root;
	consSum ++;

	// 最短临时变量
	Arc* shortest = (Arc*)malloc(sizeof(Arc));
	shortest->enter = ' ';
	shortest->quit = ' ';
	shortest->adv = Max;


	// 把所有的顶点都连接起来
	while(consSum < graph->vesNum) {

		// 遍历所有已经找到的顶点找出最短的边（贪心算法）
		for(int i = 0; i < consSum; i++) {
			int taget = findVesIndex(cons[i],graph->vers,&(graph->vesNum));

			// 找入度部分的
			for(int ii = 0; ii < graph->vesNum; ii++) {
				if(!findFineVer(graph->vers[ii],cons,&consSum)) {
					if(graph->arc[taget][ii] != Max) {
						if(shortest->adv > graph->arc[taget][ii]) {
							shortest->enter = graph->vers[taget];
							shortest->quit = graph->vers[ii];
							shortest->adv = graph->arc[taget][ii];
						}
					}
				}
			}

			// 找出度部分的
			for(int ii = 0; ii < graph->vesNum; ii++) {
				if(!findFineVer(graph->vers[ii],cons,&consSum)) {
					if(graph->arc[ii][taget] != Max) {
						if(shortest->adv > graph->arc[ii][taget]) {
							shortest->enter = graph->vers[taget];
							shortest->quit = graph->vers[ii];
							shortest->adv = graph->arc[ii][taget];
						}
					}
				}
			}
		}

		std::cout << shortest->enter << " -> " << shortest->quit << "权:" << shortest->adv << std::endl;

		cons[consSum] = shortest->quit;
		consSum ++;


		// 清空
		shortest->enter = ' ';
		shortest->quit = ' ';
		shortest->adv = Max;

	}

	delete(shortest);
	delete(cons);

	std::cout << "生成最小树结束" << std::endl;
}




