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

	graph->arc[quitArc][enterArc]  = arc->adv;
}

/*
* Ѱ���Ƿ��Ǳ������Ķ���
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





