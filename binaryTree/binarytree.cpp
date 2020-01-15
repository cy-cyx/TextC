#include"binarytree.h"

void print(TreeNode** node,int level) {

	// 如果为空，显示空结点
	if(*node == NULL) {
		for(int i = 0; i < level; i++) {
			std::cout << "  ";
		}
		for(int i = 0; i < level; i++) {
			std::cout << "_";
		}
		std::cout<<level<<"_"<< "-" << std::endl;
	}

	else {
		// 先打印左孩子结点
		print(&(*node)->leftLeaf,level+1);

		// 打印自己
		for(int i = 0; i < level; i++) {
			std::cout << "  ";
		}
		for(int i = 0; i < level; i++) {
			std::cout << "_";
		}
		if((*node)->father == NULL) {
			std::cout <<level<<"_"<< (*node)->data << std::endl;
		} else {
			std::cout <<level<<"_"<< (*node)->data << "_f = " <<(*node)->father->data<< std::endl;
		}

		// 打印右孩子结点
		print(&(*node)->rightLeaf,level+1);
	}
}

void find(TreeNode** node,int target,int time) {
	// 找到打印出来
	if((*node)->data == target) {
		std::cout << "find target:"<<target<<",time is "<<time<<std::endl;
	} else {
		// 比目标小，如果左孩子结点有就继续找，没有就跳出
		if(target <(*node)->data) {
			if((*node)->leftLeaf == NULL) {
				std::cout <<"no find target"<<target<<std::endl;
			} else {
				find(&(*node)->leftLeaf,target,time+1);
			}
		} else {
			if((*node)->rightLeaf == NULL) {
				std::cout <<"no find target:"<<target<<std::endl;
			} else {
				find(&(*node)->rightLeaf,target,time+1);
			}
		}
	}
}

void findMax(TreeNode** node) {
	// 如果右孩子结点为空时，就说明还是最大了，不然就继续找
	if((*node)->rightLeaf == NULL) {
		std::cout << "max leaf is "<<(*node)->data<<std::endl;
	} else {
		findMax(&(*node)->rightLeaf);
	}
}

void findMin(TreeNode** node) {
	// 如果左孩子结点为空时，就说明还是最小了，不然就继续找
	if((*node)->leftLeaf == NULL) {
		std::cout << "min leaf is "<<(*node)->data<<std::endl;
	} else {
		findMin(&(*node)->leftLeaf);
	}
}

void traversalLDR(TreeNode** root) {
	// 先遍历左树
	if((*root)->leftLeaf != NULL) {
		traversalLDR(&(*root)->leftLeaf);
	}

	// 打印根
	std::cout<<(*root)->data<<" ";

	// 遍历右树
	if((*root)->rightLeaf != NULL) {
		traversalLDR(&(*root)->rightLeaf);
	}
}

void traversalRDL(TreeNode** root) {
	// 右树
	if((*root)->rightLeaf != NULL) {
		traversalRDL(&(*root)->rightLeaf);
	}

	// 打印根
	std::cout<<(*root)->data<<" ";

	// 左树
	if((*root)->leftLeaf != NULL) {
		traversalRDL(&(*root)->leftLeaf);
	}
}

int getTreeHeight(TreeNode* node) {
	if(node == NULL) return 0;
	return(std::max(getTreeHeight(node->leftLeaf),getTreeHeight(node->rightLeaf)) + 1);
}
