#include <iostream>
#include<stdlib.h>
#include "findbinarytree.h"
#include "balancebinarytree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

template<class T>
int length(T& arr) {
	return sizeof(arr) / sizeof(arr[0]);
}

int main(int argc, char** argv) {

	TreeNode* findRoot = NULL;
	TreeNode* balanceRoot = NULL;

	int datas[] = {1,43,6,82,74,99,45,73,23,1,5,33,3,2,9,4,5,63,2,64,3,3};

	int l = length(datas);

//	for(int index = 0; index < l; index++) {
//		insertLeaf_find(&findRoot,datas[index]);
//	}

//	std::cout<<"当前树的高度为："<<getTreeHeight(findRoot)<<std::endl;
//
//	print(&findRoot,0);
//
//	find(&findRoot,9,0);
//
//	find(&findRoot,10,0);
//
//	findMax(&findRoot);
//
//	findMin(&findRoot);
//
//	deleteLeaf_find(&findRoot,43);
//
//	print(&findRoot,0);
//
//	traversalLDR(&findRoot);
//
//	std::cout<<"LDR遍历结束"<<std::endl;
//
//	traversalRDL(&findRoot);
//
//	std::cout<<"RDL遍历结束"<<std::endl;
//

	for(int index = 0; index < l; index++) {
		insert_balance(&balanceRoot,datas[index]);
	}

//	std::cout<<"当前树的高度为："<<getTreeHeight(balanceRoot)<<std::endl;

	print(&balanceRoot,0);
	
	delete_balance(&balanceRoot,99);
	
	print(&balanceRoot,0);
	
	delete_balance(&balanceRoot,74);
	
	print(&balanceRoot,0);
	
	delete_balance(&balanceRoot,43);
	
	print(&balanceRoot,0);

	traversalLDR(&balanceRoot);

	std::cout<<"LDR遍历结束"<<std::endl;

	return 0;
}
