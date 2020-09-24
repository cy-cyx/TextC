#include <iostream>
#include "graph.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Graph* graph = (Graph*)malloc(sizeof(Graph));

	initGraph(graph);

	// ¶¥µ×a,b,c,d
	insertVer(graph,'a');
	insertVer(graph,'b');
	insertVer(graph,'c');
	insertVer(graph,'d');

	printGraph(graph);

	free(graph);

	return 0;
}
