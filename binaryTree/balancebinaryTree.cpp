#include "balancebinarytree.h"

/*
 * 获得结点的平衡系数 -1 0 1
 */
int getBalanceFactor(TreeNode* node) {
	return getTreeHeight(node->leftLeaf) - getTreeHeight(node->rightLeaf);
}

void LL(TreeNode* node) {
	TreeNode* father = node->father;
	TreeNode* right = node->rightLeaf;

	// 修改双亲结点的指向
	if(father->leftLeaf != NULL && father->leftLeaf == node) {
		father->leftLeaf = right;
	} else {
		father->rightLeaf = right;
	}

	// 修改自己
	node->father = right;
	node->rightLeaf = right->leftLeaf;

	// 修改左旋涉及到的结点
	right->father = father;
	right->leftLeaf = node;

}

void RR(TreeNode* node) {
	TreeNode* father = node->father;
	TreeNode* left = node->leftLeaf;

	// 修改双亲结点的指向
	if(father->leftLeaf != NULL && father->leftLeaf == node) {
		father->leftLeaf = left;
	} else {
		father->rightLeaf = left;
	}

	// 修改自己
	node->father = left;
	node->leftLeaf = left->rightLeaf;

	// 修改右旋涉及到的结点
	left->father = father;
	left->rightLeaf = node;
}

void RL(TreeNode* node) {

	// 该结点的右孩子结点先右旋，再左旋
	RR(node->rightLeaf);
	LL(node);
}

void LR(TreeNode* node) {
	// 该结点的右孩子结点先左旋，再右旋
	LL(node->leftLeaf);
	RR(node);

}

void insert_balance(TreeNode** node,TreeNode* root,int data) {

	// 如果结点为空， 插入该值，并往上遍历找不平衡结点
	if(*node == NULL) {

		// 插入值
		*node = (TreeNode*)malloc(sizeof(TreeNode));
		(*node)->leftLeaf = NULL;
		(*node)->rightLeaf = NULL;
		(*node)->father = root;
		(*node)->data = data;

		// 如果是根结点就直接不管
		if(root == NULL) {
			return;
		}

		TreeNode* imBalanceNode = root;
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
			// 需要左旋 再判断是LL还是RL
			int rightBalanceFactor = getBalanceFactor(imBalanceNode->rightLeaf);
			if(rightBalanceFactor > 0) {
				// RL
				RL(imBalanceNode);

			} else {
				// LL
				LL(imBalanceNode);

			}
		} else {
			// 需要右旋 再判断是RR LR
			int leftBalanceFactor = getBalanceFactor(imBalanceNode->leftLeaf);
			if(leftBalanceFactor < 0) {
				// LR
				LR(imBalanceNode);

			} else {
				// RR
				RR(imBalanceNode);

			}
		}


	} else {
		if(data < (*node)->data) {
			insert_balance(&(*node)->leftLeaf,*node,data);
		} else if(data > (*node)->data) {
			insert_balance(&(*node)->rightLeaf,*node,data);
		} else {
			std::cout <<"repeat target : "<< data << std::endl;
		}
	}
}


