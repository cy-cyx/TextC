#ifndef GRAPH_BASE 

#define GRAPH_BASE

#define MAXVES 100  // 最大存在的顶点数 

typedef struct{
	char ves[MAXVES]  // 放顶点数 
	int arc[MAXVES][MAXVES]  // 放度 
	
	int vesNum 
};

#endif 
