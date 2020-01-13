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

	TreeNode* root = NULL;

	int datas[] = {43,6,82,74,99,45,73,23,1,5,33,3,2,9,4,5,63,2,64,3,3};

	int l = length(datas);

//	for(int index = 0; index < l; index++) {
//		insertLeaf_find(&root,datas[index]);
//	}
//
//	print(&root,0);
//
//	find(&root,9,0);
//
//	find(&root,10,0);
//
//	findMax(&root);
//
//	findMin(&root);
//
//	deleteLeaf_find(&root,6);
//
//	print(&root,0);
//
//	traversalLDR(&root);
//
//	std::cout<<"LDR遍历结束"<<std::endl;
//
//	traversalRDL(&root);
//
//	std::cout<<"RDL遍历结束"<<std::endl;
//
//	std::cout<<"当前树的高度为："<<getTreeHeight(root)<<std::endl;

	for(int index = 0; index < l; index++) {
		insert_balance(&root,NULL,datas[index]);
	}

	print(&root,0);

	return 0;
}
