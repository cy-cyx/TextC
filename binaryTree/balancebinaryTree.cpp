#include "balancebinarytree.h"

/*
 * 获得结点的平衡系数 -1 0 1
 */
int getBalanceFactor(TreeNode* node) {
	return getTreeHeight(node->leftLeaf) - getTreeHeight(node->rightLeaf);
}

void LL(TreeNode* imBalanceNode,TreeNode** root) {
	TreeNode* fatherNode = imBalanceNode->father;
	TreeNode* rightNode	= imBalanceNode->rightLeaf;

	// 先修改根结点
	if(fatherNode == NULL) {
		*root = rightNode;
	} else {
		if(fatherNode->leftLeaf == imBalanceNode) {
			fatherNode->leftLeaf = rightNode;
		} else {
			fatherNode->rightLeaf = rightNode;
		}
	}

	// 修改自己
	imBalanceNode->father =  rightNode;
	imBalanceNode->rightLeaf = rightNode->leftLeaf;
	
	// 需要修改涉及到子孩子树 
	TreeNode* tempNode =  rightNode->leftLeaf;
	if(tempNode != NULL) {
		tempNode->father = imBalanceNode;
	}


	// 修改左旋影响到结点
	rightNode->father = fatherNode;
	rightNode->leftLeaf = imBalanceNode;
}

void RR(TreeNode* imBalanceNode,TreeNode** root) {
	TreeNode* fatherNode = imBalanceNode->father;
	TreeNode* leftNode = imBalanceNode->leftLeaf;

	// 先修改根结点
	if(fatherNode == NULL) {
		*root = leftNode;
	} else {
		if(fatherNode->leftLeaf == imBalanceNode) {
			fatherNode->leftLeaf = leftNode;
		} else {
			fatherNode->rightLeaf = leftNode;
		}
	}

	// 修改自己
	imBalanceNode->father =  leftNode;
	imBalanceNode->leftLeaf = leftNode->rightLeaf;
	
	// 需要修改涉及到子孩子树 
	TreeNode* tempNode = leftNode->rightLeaf;
	if(tempNode != NULL) {
		tempNode->father = imBalanceNode;
	}

	// 修改左旋影响到结点
	leftNode->father = fatherNode;
	leftNode->rightLeaf = imBalanceNode;
}

void RL(TreeNode* imBalanceNode,TreeNode** root) {
	RR(imBalanceNode->rightLeaf,root);
	LL(imBalanceNode,root);
}

void LR(TreeNode* imBalanceNode,TreeNode** root) {
	LL(imBalanceNode->leftLeaf,root);
	RR(imBalanceNode,root);
}

void insert_balance(TreeNode** root,int data) {

	// 根结点特别处理
	if(*root == NULL) {
		*root = (TreeNode*)malloc(sizeof(TreeNode));
		(*root)->leftLeaf = NULL;
		(*root)->rightLeaf = NULL;
		(*root)->father = NULL;
		(*root)->data = data;
		return;
	}

	TreeNode* targetNode = *root;

	// 找到对应的位置插入
	while(1) {
		if(data < targetNode->data) {
			if(targetNode->leftLeaf == NULL) {
				TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
				newNode->leftLeaf = NULL;
				newNode->rightLeaf = NULL;
				newNode->father = targetNode;
				newNode->data = data;
				targetNode->leftLeaf = newNode;
				break;
			} else {
				targetNode = targetNode->leftLeaf;
			}
		} else if(data > targetNode->data) {
			if(targetNode->rightLeaf == NULL) {
				TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
				newNode->leftLeaf = NULL;
				newNode->rightLeaf = NULL;
				newNode->father = targetNode;
				newNode->data = data;
				targetNode->rightLeaf = newNode;
				break;
			} else {
				targetNode = targetNode->rightLeaf;
			}
		} else {
			std::cout <<"repeat target : "<< data << std::endl;
			return;
		}
	}

	TreeNode* imBalanceNode = targetNode;
	int balanceFactor = 0;

	// 找最近的不平衡结点
	while(1) {
		balanceFactor = getBalanceFactor(imBalanceNode);

		if(abs(balanceFactor) > 1) {
			std::cout<<"appear imbalance"<<std::endl;
			break;
		}

		if(imBalanceNode->father == NULL) {
			return;
		}

		imBalanceNode = imBalanceNode->father;
	}

	// 通过旋转纠正平衡 通过判断平衡系数 确定左旋转还是右旋转
	if(balanceFactor < 0) {
		// 需要左旋转,再判断LL RL
		if(getBalanceFactor(imBalanceNode->rightLeaf)>0) {
			RL(imBalanceNode,root);
		} else {
			LL(imBalanceNode,root);
		}
	} else {
		// 需要右旋转，再判断RR LR
		if(getBalanceFactor(imBalanceNode->leftLeaf) <0) {
			LR(imBalanceNode,root);
		} else {
			RR(imBalanceNode,root);
		}
	}

}
