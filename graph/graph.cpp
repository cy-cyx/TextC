#include "graph.h"


void initGraph(Graph* graph) {

	// ȫ���ó�ʼ��״̬
	graph->vesNum = 0;
	graph->arcNum = 0;

	// �������� ' '
	for(int i = 0; i < MAXVER; i++) {
		graph->vers[i] = blankVer;
	}

	// ���� ��Ϊ����
	for(int i = 0; i < MAXVER; i++) {
		for(int ii = 0; ii < MAXVER; ii++) {
			graph->arc[i][ii] = Max;
		}
	}

}

void printGraph(Graph* graph) {

	std::cout << "��ӡͼ��ʼ______" << std::endl;

	std::cout << "��ӡ����:";
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

	std::cout << "��ӡͼ����______" << std::endl;
}

void insertVer(Graph* graph,char ver) {

	// �����ظ�������ͬ�Ķ���
	for(int i = 0; i < graph->vesNum; i++) {
		if(graph->vers[i] == ver) {
			return;
		}
	}

	// ���붥������
	graph->vesNum ++;
	graph->vers[graph->vesNum - 1] = ver;
}

void insertArc(Graph* graph,Arc* arc) {
	int enterArc; // ��
	int quitArc;  // ��

	// ���
	for(int i = 0; i < graph->vesNum; i++) {

		if(graph->vers[i] == arc->enter) {

			enterArc = i;

			break;
		}

		if(i == graph->vesNum - 1) {
			return;
		}
	}

	// ����
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
* Ѱ���Ƿ��Ǳ������Ķ���
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

	std::cout << "��һ�����Ӷ���" << lastTarget << "--��������:" << target << std::endl;

	fineVers[*fineVersIndex]= target;
	*fineVersIndex = *fineVersIndex + 1;


	int verIndex = 0;

	// ͨ����Ⱥͳ��� ����fineVersIndex��صĻ�

	// �ҵ����ڶ��������е�λ��
	for(int i = 0; i < graph->vesNum; i++) {
		if(graph->vers[i] == target) {
			verIndex = i;
			break;
		}
	}

	// ���
	for(int i = 0; i < graph->vesNum; i++) {

		if(graph->arc[i][verIndex] != Max) {

			char nextVer = graph->vers[i];
			if(!findFineVer(nextVer,fineVers,fineVersIndex)) {
				dfsInner(graph,target,nextVer,fineVers,fineVersIndex);
			}
		}
	}

	// ����
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

	std::cout << "��ʼ��ȱ���______" << std::endl;

	// �����ҵ��Ķ���
	char* fineVers = (char*)malloc(sizeof(char) * graph->vesNum);
	// �ҵ��˼���
	int fineVersIndex = 0;

	// ��ʼ����
	dfsInner(graph,' ',graph->vers[0],fineVers,&fineVersIndex);

	std::cout << "��ȱ�������______" << std::endl;
}



void bfs(Graph* graph) {

	std::cout << "��ʼ��ȱ���______" << std::endl;

	// �����ҵ��Ķ���
	char* fineVers = (char*)malloc(sizeof(char) * graph->vesNum);
	// �ҵ��˼���
	int fineVersIndex = 0;

	// ʹ�ö��б������
	Queue* q = new Queue();

	// �����һ����
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

		std::cout<< "����"<< temp->last << "���㣺" << temp->c << std::endl;

		// �������ҵ�����
		fineVers[fineVersIndex]= temp->c;
		fineVersIndex = fineVersIndex + 1;

		// �ҵ��ڶ��������е�λ��
		int verIndex = 0;
		for(int i = 0; i < graph->vesNum; i++) {
			if(graph->vers[i] == temp->c) {
				verIndex = i;
				break;
			}
		}

		// �������
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

		// ����
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

	std::cout << "������ȱ���______" << std::endl;

}

/*
* ֵ�������е�λ��
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
	std::cout << "��ʼ������С��(����ķ�㷨)" << std::endl;

	std::cout << "��Ϊ��" << root << std::endl;

	int consSum = 0;
	// ���Ѿ����ӵĶ���
	char* cons = (char*)malloc(sizeof(char) * graph->vesNum);

	cons[consSum] = root;
	consSum ++;

	// �����ʱ����
	Arc* shortest = (Arc*)malloc(sizeof(Arc));
	shortest->enter = ' ';
	shortest->quit = ' ';
	shortest->adv = Max;


	// �����еĶ��㶼��������
	while(consSum < graph->vesNum) {

		// ���������Ѿ��ҵ��Ķ����ҳ���̵ıߣ�̰���㷨��
		for(int i = 0; i < consSum; i++) {
			int taget = findVesIndex(cons[i],graph->vers,&(graph->vesNum));

			// ����Ȳ��ֵ�
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

			// �ҳ��Ȳ��ֵ�
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

		std::cout << shortest->enter << " -> " << shortest->quit << "Ȩ:" << shortest->adv << std::endl;

		cons[consSum] = shortest->quit;
		consSum ++;


		// ���
		shortest->enter = ' ';
		shortest->quit = ' ';
		shortest->adv = Max;

	}

	delete(shortest);
	delete(cons);

	std::cout << "������С������" << std::endl;
}

void kruskal(Graph* graph) {

	std::cout << "��ʼ������С��������³˹����" << std::endl;

	// �ҳ����б�
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


	// �Ȱѱߴ�С��������

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

		// ������ǰ��
		allArc[tempSortIndex].enter = allArc[i].enter;
		allArc[tempSortIndex].quit = allArc[i].quit;
		allArc[tempSortIndex].adv = allArc[i].adv;

		allArc[i].enter = tempSort->enter;
		allArc[i].quit = tempSort->quit;
		allArc[i].adv = tempSort->adv;

		// ����
		tempSort->adv = Max;
		tempSortIndex = i+1;
	}

	delete(tempSort);



	// ��ʼƴ���� ��������������㶼û�г����Լ�����
	// �������һ����û�г��������е���ƴ��
	// ��������㶼���� �ж��Ƿ���ͬһ������ ���ǣ�������һ

	int consSum = 0;
	// ���Ѿ����ӵĶ���
	char* cons = (char*)malloc(sizeof(char) *graph->vesNum);

	// �����ĸ�
	LinkedList* roots = new LinkedList();

	char ver1 = ' ';
	bool ver1Cons = false;
	char ver2 = ' ';
	bool ver2Cons = false;

	// ��ʼ������
	for(int i = 0; i < graph->arcNum; i++) {

		Arc arc = allArc[i];

		ver1 = arc.enter;
		ver2 = arc.quit;

		// ���ж������ıߵĶ���״̬
		ver1Cons = findFineVer(ver1,cons,&consSum);
		ver2Cons = findFineVer(ver2,cons,&consSum);

		// ����������������
		if(!ver1Cons&&!ver2Cons) {

			LinkedListNode* n1 = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			n1->c = ver1;
			n1->tail = LinkedListNodeNull;

			LinkedListNode* n2 = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			n2->c = ver2;
			n2->tail = LinkedListNodeNull;

			// ����һ������
			roots->addRoot(n1);

			// �����ӵ�ͬһ����
			linkedListAdd(n1,n2);

			// ���������ӵ����ҵ����б���
			cons[consSum] = arc.enter;
			consSum++;
			cons[consSum] = arc.quit;
			consSum++;

			std::cout <<  arc.enter << " <-> " << arc.quit << "Ȩ��" << arc.adv << " (�����㶼û����)" << std::endl;
		}
		// ֻ��һ����(2��)
		else if(!ver1Cons&&ver2Cons) {
			// �ж����ǿ�������ȥ
			LinkedListRootNode* temp = roots->root;

			do {
				if(linkedListContain(temp->root,ver2)) {
					break;
				}

				temp = temp->tail;

			} while(temp != LinkedListRootNodeNull);

			// �ҵ��ǿ���Ȼ��Ͳ��ȥ

			LinkedListNode* n = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			n->c = ver1;
			n->tail = LinkedListNodeNull;

			linkedListAdd(temp->root,n);

			cons[consSum] = ver1;
			consSum++;

			std::cout <<  arc.enter << " <-> " << arc.quit << "Ȩ��" << arc.adv << " (һ�������)" << std::endl;

		}

		// ֻ��һ����(1��)
		else if(!ver2Cons&&ver1Cons) {
			// �ж����ǿ�������ȥ
			LinkedListRootNode* temp = roots->root;

			do {
				if(linkedListContain(temp->root,ver1)) {
					break;
				}

				temp = temp->tail;

			} while(temp != LinkedListRootNodeNull);

			// �ҵ��ǿ���Ȼ��Ͳ��ȥ

			LinkedListNode* n = (LinkedListNode*)malloc(sizeof(LinkedListNode));
			n->c = ver2;
			n->tail = LinkedListNodeNull;

			linkedListAdd(temp->root,n);

			cons[consSum] = ver2;
			consSum++;

			std::cout <<  arc.enter << " <-> " << arc.quit << "Ȩ��" << arc.adv << " (һ�������)"  << std::endl;
		}
		// ȫ��
		else {

			// �ж��Ƿ���ͬһ������ͬһ�����Ͳ���  ���ھ��������ϳ�һ��

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

				std::cout << "���������Ѿ���ͬһ������" << std::endl;
			} else {
				// �������ϲ�

				linkedListAdd(temp1->root,temp2->root);
				roots->deleteRoot(temp2->root);

				std::cout <<  arc.enter << " <-> " << arc.quit << "Ȩ��" << arc.adv << " (��������֣����úϲ�)"  << std::endl;
			}
		}
	}

	std::cout << "������С������" << std::endl;
}





