#include "base.h"

void insert(TreeNode** node,int data) {

	// 若子叶为空,就放在子叶的位置即可
	if(*node == NULL) {
		*node = (TreeNode*)malloc(sizeof(TreeNode));
		(*node)->leftLeaf = NULL;
		(*node)->rightLeaf = NULL;
		(*node)->data = data;
	}
	// 如果子叶不为空，就往子叶的子叶继续放下去，按照递归
	else {
		if(data < (*node)->data) {
			insert(&(*node)->leftLeaf,data);
		} else if(data > (*node)->data) {
			insert(&(*node)->rightLeaf,data);
		} else {
			std::cout <<"repeat target : "<< data << std::endl;
		}
	}
}

void print(TreeNode** node,int level) {

	// 如果为空，显示空子叶
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
		// 先打印左节点
		print(&(*node)->leftLeaf,level+1);

		// 打印自己
		for(int i = 0; i < level; i++) {
			std::cout << "  ";
		}
		for(int i = 0; i < level; i++) {
			std::cout << "_";
		}
		std::cout <<level<<"_"<< (*node)->data << std::endl;

		// 打印右节点
		print(&(*node)->rightLeaf,level+1);
	}
}

void find(TreeNode** node,int target,int time) {
	// 找到打印出来
	if((*node)->data == target) {
		std::cout << "find target:"<<target<<",time is "<<time<<std::endl;
	} else {
		// 比目标小，如果左子叶有就继续找，没有就跳出
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
	// 如果右子叶为空时，就说明还是最大了，不然就继续找
	if((*node)->rightLeaf == NULL) {
		std::cout << "max leaf is "<<(*node)->data<<std::endl;
	} else {
		findMax(&(*node)->rightLeaf);
	}
}

void findMin(TreeNode** node) {
	// 如果左子叶为空时，就说明还是最小了，不然就继续找
	if((*node)->leftLeaf == NULL) {
		std::cout << "min leaf is "<<(*node)->data<<std::endl;
	} else {
		findMin(&(*node)->leftLeaf);
	}
}

