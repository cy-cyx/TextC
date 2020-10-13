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
	QueueNode* fristNode = new QueueNode();
	fristNode->last = ' ';
	fristNode->c = graph->vers[0];
	fristNode->next = NODE_NULL;
	q->enqueue(fristNode);

	QueueNode* temp = NODE_NULL;

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
					QueueNode* n = new QueueNode();
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
					QueueNode* n = new QueueNode();
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

void kruskal(Graph* graph) {

	std::cout << "开始生成最小树（克里鲁斯卡）" << std::endl;

	// 找出所有标
	int allArcIndex = 0;
	Arc* allArc = (Arc*)malloc(sizeof(Arc) * graph->arcNum);


	for(int i = 0; i < graph->vesNum; i++) {
		for(int ii = 0; ii < graph->vesNum; ii++) {
			if(graph->arc[i][ii] != Max) {

				allArc[allArcIndex].enter = graph->vers[i];
				allArc[allArcIndex].quit = graph->vers[ii];
				allArc[allArcIndex].adv = graph->arc[i][ii];

				allArcIndex++;
			}
		}
	}


	// 先把边从小到大排序

	int tempSortIndex = 0;
	Arc* tempSort = (Arc*)malloc(sizeof(Arc));
	tempSort->adv = Max;

	for(int i = 0; i < graph->arcNum; i++) {

		for(int ii = i; ii<graph->arcNum; ii++) {
			if(allArc[ii].adv < tempSort->adv) {
				tempSortIndex = ii;

				tempSort->enter = allArc[ii].enter;
				tempSort->quit = allArc[ii].quit;
				tempSort->adv = allArc[ii].adv;
			}
		}

		// 交换到前面
		allArc[tempSortIndex].enter = allArc[i].enter;
		allArc[tempSortIndex].quit = allArc[i].quit;
		allArc[tempSortIndex].adv = allArc[i].adv;

		allArc[i].enter = tempSort->enter;
		allArc[i].quit = tempSort->quit;
		allArc[i].adv = tempSort->adv;

		// 重置
		tempSort->adv = Max;
		tempSortIndex = i+1;
	}

	delete(tempSort);



	// 开始拼成树 如果这条弧两个点都没有出现自己成树
	// 如果其中一个点没有出现找现有的树拼接
	// 如果两个点都出现 判断是否是同一个棵树 不是，两树合一

	int consSum = 0;
	// 放已经连接的顶点
	char* cons = (char*)malloc(sizeof(char) *graph->vesNum);

	// 放树的根
	LinkedList* roots = new LinkedList();

	char ver1 = ' ';
	bool ver1Cons = false;
	char ver2 = ' ';
	bool ver2Cons = false;

	// 开始遍历边
	for(int i = 0; i < graph->arcNum; i++) {

		Arc arc = allArc[i];

		ver1 = arc.enter;
		ver2 = arc.quit;

		// 先判断这条的边的顶点状态
		ver1Cons = findFineVer(ver1,cons,&consSum);
		ver2Cons = findFineVer(ver2,cons,&consSum);

		// 两个都不在连接中
		if(!ver1Cons&&!ver2Cons) {

			LinkedListNode* n1 = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			n1->c = ver1;
			n1->tail = LinkedListNodeNull;

			LinkedListNode* n2 = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			n2->c = ver2;
			n2->tail = LinkedListNodeNull;

			// 建立一棵新树
			roots->addRoot(n1);

			// 两个加到同一棵树
			linkedListAdd(n1,n2);

			// 把这两个加到已找到的列表中
			cons[consSum] = arc.enter;
			consSum++;
			cons[consSum] = arc.quit;
			consSum++;

			std::cout <<  arc.enter << " <-> " << arc.quit << "权：" << arc.adv << " (两个点都没出现)" << std::endl;
		}
		// 只有一个在(2在)
		else if(!ver1Cons&&ver2Cons) {
			// 判断在那棵树加上去
			LinkedListRootNode* temp = roots->root;

			do {
				if(linkedListContain(temp->root,ver2)) {
					break;
				}

				temp = temp->tail;

			} while(temp != LinkedListRootNodeNull);

			// 找到那棵树然后就插进去

			LinkedListNode* n = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			n->c = ver1;
			n->tail = LinkedListNodeNull;

			linkedListAdd(temp->root,n);

			cons[consSum] = ver1;
			consSum++;

			std::cout <<  arc.enter << " <-> " << arc.quit << "权：" << arc.adv << " (一个点出现)" << std::endl;

		}

		// 只有一个在(1在)
		else if(!ver2Cons&&ver1Cons) {
			// 判断在那棵树加上去
			LinkedListRootNode* temp = roots->root;

			do {
				if(linkedListContain(temp->root,ver1)) {
					break;
				}

				temp = temp->tail;

			} while(temp != LinkedListRootNodeNull);

			// 找到那棵树然后就插进去

			LinkedListNode* n = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			n->c = ver2;
			n->tail = LinkedListNodeNull;

			linkedListAdd(temp->root,n);

			cons[consSum] = ver2;
			consSum++;

			std::cout <<  arc.enter << " <-> " << arc.quit << "权：" << arc.adv << " (一个点出现)"  << std::endl;
		}
		// 全在
		else {

			// 判断是否在同一棵树，同一棵树就不管  不在就两棵树合成一棵

			LinkedListRootNode* temp1 = roots->root;

			do {
				if(linkedListContain(temp1->root,ver1)) {
					break;
				}

				temp1 = temp1->tail;

			} while(temp1 != LinkedListRootNodeNull);


			LinkedListRootNode* temp2 = roots->root;

			do {
				if(linkedListContain(temp2->root,ver2)) {
					break;
				}

				temp2 = temp2->tail;

			} while(temp2 != LinkedListRootNodeNull);

			if(temp1 == temp2) {

				std::cout << "两个顶点已经在同一棵树上" << std::endl;
			} else {
				// 两棵树合并

				linkedListAdd(temp1->root,temp2->root);
				roots->deleteRoot(temp2->root);

				std::cout <<  arc.enter << " <-> " << arc.quit << "权：" << arc.adv << " (两个点出现，两棵合并)"  << std::endl;
			}
		}
	}

	std::cout << "生成最小数结束" << std::endl;
}





