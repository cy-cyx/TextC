#include "balancebinarytree.h"

/*
 * ��ý���ƽ��ϵ�� -1 0 1
 */
int getBalanceFactor(TreeNode* node) {
	return getTreeHeight(node->leftLeaf) - getTreeHeight(node->rightLeaf);
}

void LL(TreeNode* node) {
	TreeNode* father = node->father;
	TreeNode* right = node->rightLeaf;

	// �޸�˫�׽���ָ��
	if(father->leftLeaf != NULL && father->leftLeaf == node) {
		father->leftLeaf = right;
	} else {
		father->rightLeaf = right;
	}

	// �޸��Լ�
	node->father = right;
	node->rightLeaf = right->leftLeaf;

	// �޸������漰���Ľ��
	right->father = father;
	right->leftLeaf = node;

}

void RR(TreeNode* node) {
	TreeNode* father = node->father;
	TreeNode* left = node->leftLeaf;

	// �޸�˫�׽���ָ��
	if(father->leftLeaf != NULL && father->leftLeaf == node) {
		father->leftLeaf = left;
	} else {
		father->rightLeaf = left;
	}

	// �޸��Լ�
	node->father = left;
	node->leftLeaf = left->rightLeaf;

	// �޸������漰���Ľ��
	left->father = father;
	left->rightLeaf = node;
}

void RL(TreeNode* node) {

	// �ý����Һ��ӽ����������������
	RR(node->rightLeaf);
	LL(node);
}

void LR(TreeNode* node) {
	// �ý����Һ��ӽ����������������
	LL(node->leftLeaf);
	RR(node);

}

void insert_balance(TreeNode** node,TreeNode* root,int data) {

	// ������Ϊ�գ� �����ֵ�������ϱ����Ҳ�ƽ����
	if(*node == NULL) {

		// ����ֵ
		*node = (TreeNode*)malloc(sizeof(TreeNode));
		(*node)->leftLeaf = NULL;
		(*node)->rightLeaf = NULL;
		(*node)->father = root;
		(*node)->data = data;

		// ����Ǹ�����ֱ�Ӳ���
		if(root == NULL) {
			return;
		}

		TreeNode* imBalanceNode = root;
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
			// ��Ҫ���� ���ж���LL����RL
			int rightBalanceFactor = getBalanceFactor(imBalanceNode->rightLeaf);
			if(rightBalanceFactor > 0) {
				// RL
				RL(imBalanceNode);

			} else {
				// LL
				LL(imBalanceNode);

			}
		} else {
			// ��Ҫ���� ���ж���RR LR
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


