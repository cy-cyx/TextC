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
