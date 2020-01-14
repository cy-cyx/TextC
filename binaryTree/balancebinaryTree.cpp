#include "balancebinarytree.h"

/*
 * ��ý���ƽ��ϵ�� -1 0 1
 */
int getBalanceFactor(TreeNode* node) {
	return getTreeHeight(node->leftLeaf) - getTreeHeight(node->rightLeaf);
}

void LL(TreeNode* imBalanceNode,TreeNode** root) {
	TreeNode* fatherNode = imBalanceNode->father;
	TreeNode* rightNode	= imBalanceNode->rightLeaf;

	// ���޸ĸ����
	if(fatherNode == NULL) {
		*root = rightNode;
	} else {
		if(fatherNode->leftLeaf == imBalanceNode) {
			fatherNode->leftLeaf = rightNode;
		} else {
			fatherNode->rightLeaf = rightNode;
		}
	}

	// �޸��Լ�
	imBalanceNode->father =  rightNode;
	imBalanceNode->rightLeaf = rightNode->leftLeaf;
	
	// ��Ҫ�޸��漰���Ӻ����� 
	TreeNode* tempNode =  rightNode->leftLeaf;
	if(tempNode != NULL) {
		tempNode->father = imBalanceNode;
	}


	// �޸�����Ӱ�쵽���
	rightNode->father = fatherNode;
	rightNode->leftLeaf = imBalanceNode;
}

void RR(TreeNode* imBalanceNode,TreeNode** root) {
	TreeNode* fatherNode = imBalanceNode->father;
	TreeNode* leftNode = imBalanceNode->leftLeaf;

	// ���޸ĸ����
	if(fatherNode == NULL) {
		*root = leftNode;
	} else {
		if(fatherNode->leftLeaf == imBalanceNode) {
			fatherNode->leftLeaf = leftNode;
		} else {
			fatherNode->rightLeaf = leftNode;
		}
	}

	// �޸��Լ�
	imBalanceNode->father =  leftNode;
	imBalanceNode->leftLeaf = leftNode->rightLeaf;
	
	// ��Ҫ�޸��漰���Ӻ����� 
	TreeNode* tempNode = leftNode->rightLeaf;
	if(tempNode != NULL) {
		tempNode->father = imBalanceNode;
	}

	// �޸�����Ӱ�쵽���
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

	// ������ر���
	if(*root == NULL) {
		*root = (TreeNode*)malloc(sizeof(TreeNode));
		(*root)->leftLeaf = NULL;
		(*root)->rightLeaf = NULL;
		(*root)->father = NULL;
		(*root)->data = data;
		return;
	}

	TreeNode* targetNode = *root;

	// �ҵ���Ӧ��λ�ò���
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

	// ������Ĳ�ƽ����
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

	// ͨ����ת����ƽ�� ͨ���ж�ƽ��ϵ�� ȷ������ת��������ת
	if(balanceFactor < 0) {
		// ��Ҫ����ת,���ж�LL RL
		if(getBalanceFactor(imBalanceNode->rightLeaf)>0) {
			RL(imBalanceNode,root);
		} else {
			LL(imBalanceNode,root);
		}
	} else {
		// ��Ҫ����ת�����ж�RR LR
		if(getBalanceFactor(imBalanceNode->leftLeaf) <0) {
			LR(imBalanceNode,root);
		} else {
			RR(imBalanceNode,root);
		}
	}

}
