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

void delete_balance(TreeNode** root,int target) {

	TreeNode* imBalanceNode;

	// ���ò��Ҷ�������ɾ���߼�����ɾ������б���ƽ�����
	TreeNode* targetNode = NULL;
	TreeNode* targetFatherNode = NULL;
	bool isLeft = false;

	// ���ҳ���Ӧ�Ľ��
	targetNode = *root;

	while(targetNode->data != target) {
		targetFatherNode = targetNode;

		// ���������ӽ����
		TreeNode* tempNode;
		if(target < targetNode->data) {
			isLeft = true;
			tempNode =  targetNode->leftLeaf;
		} else {
			isLeft = false;
			tempNode = targetNode->rightLeaf;
		}
		// ������µĺ��ӽ��û�еĻ���˵������û��������
		if(tempNode == NULL) {
			std::cout<<"delete : no this leaf"<<target<<std::endl;
			return;
		} else {
			targetNode = tempNode;
		}
	}

	// �Ҷ�Ӧ�Ľ����жϸý��ĸ�������Ϊ��˵���ý��Ϊ��
	if(targetFatherNode == NULL) {
		// ����Ǹ�

		// ���1��û�к��ӽ�㣬ֱ���ÿո�
		if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf ==NULL) {
			// ����ע��Ҫ�����ڴ�
			*root = NULL;
			delete targetNode;

			std::cout << "�ɹ�ɾ����㣬staget = "<< target << std::endl;
			return;
		}
		// ���2��3��������ҽ���һ�����ӽ��
		else if(targetNode->leftLeaf != NULL&&targetNode->rightLeaf == NULL) {
			TreeNode* tempNode = targetNode->leftLeaf;
			tempNode->father = NULL;
			*root  = tempNode;
			delete targetNode;

			std::cout << "�ɹ�ɾ����㣬staget = "<< target << std::endl;
			return;
		} else if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf != NULL) {
			TreeNode* tempNode = targetNode->rightLeaf;
			tempNode->father = NULL;
			*root  = tempNode;
			delete targetNode;

			std::cout << "�ɹ�ɾ����㣬staget = "<< target << std::endl;
			return;
		}
		// ���4���������ӽ�㶼�ڣ������ӽ���е����ȥ��Ϊ��
		else {
			TreeNode* maxChildFatherNode = NULL;
			TreeNode* childNode = targetNode->leftLeaf;
			// �����ӽ�㣨���������Ľ��
			while(childNode->rightLeaf != NULL) {
				maxChildFatherNode = childNode;
				childNode = childNode->rightLeaf;
			}

			// �������������ӽ���Լ������ҽ��Ϊ�գ����Ͱ�ɾ���Ľ���ҽ�㣬�ӵ��ú��ӽ����Һ��ӽ����
			if(maxChildFatherNode == NULL) {

				imBalanceNode =childNode;

				TreeNode* targetRightNode = targetNode->rightLeaf;
				targetRightNode->father = childNode;

				childNode->rightLeaf = targetRightNode;
				childNode->father = NULL;
				*root  = childNode;

				delete targetNode;
			} else {

				imBalanceNode = maxChildFatherNode;

				// ֱ�ӰѸý�㣬�嵽Ҫɾ������λ��
				TreeNode* targetRightNode = targetNode->rightLeaf;
				targetRightNode->father = childNode;

				childNode->rightLeaf = targetRightNode;

				TreeNode* targetLeftNode = targetNode->leftLeaf;
				targetLeftNode->father = childNode;

				childNode->leftLeaf = targetLeftNode;

				// ����Ҫע�⣺������Ľ�㣬���ܻ��������ӽ��
				TreeNode* childLeftNode = childNode->leftLeaf;
				maxChildFatherNode->rightLeaf = childLeftNode;
				if(childLeftNode != NULL) {
					childLeftNode->father = maxChildFatherNode;
				}

				childNode->father = NULL;
				*root  = childNode;
				delete targetNode;
			}

		}
	} else {
		// ���1������ýڵ�û�к��ӽ��
		if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf == NULL) {

			imBalanceNode = targetFatherNode;

			if(isLeft) {
				targetFatherNode->leftLeaf = NULL;
			} else {
				targetFatherNode->rightLeaf = NULL;
			}
			delete targetNode;
		}
		// ���2��3�����ҽ���һ�����ӽ��
		else if(targetNode->leftLeaf != NULL&&targetNode->rightLeaf == NULL) {

			imBalanceNode = targetFatherNode;

			TreeNode* targetLeftNode = targetNode->leftLeaf;
			targetLeftNode->father = targetFatherNode;
			if(isLeft) {
				targetFatherNode->leftLeaf = targetLeftNode;
			} else {
				targetFatherNode->rightLeaf = targetLeftNode;
			}
			delete targetNode;
		} else if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf != NULL) {

			imBalanceNode = targetFatherNode;

			TreeNode* targetRightNode = targetNode->rightLeaf;
			targetRightNode->father = targetFatherNode;
			if(isLeft) {
				targetFatherNode->leftLeaf = targetRightNode;
			} else {
				targetFatherNode->rightLeaf = targetRightNode;
			}
			delete targetNode;
		}
		// ���4�����ҽ�㶼��
		else {

			TreeNode* maxChildFatherNode = NULL;
			TreeNode* childNode = targetNode->leftLeaf;

			while(childNode->rightLeaf != NULL) {
				maxChildFatherNode = childNode;
				childNode = childNode->rightLeaf;
			}

			// �������������ӽ���Լ������ҽ��Ϊ�գ����Ͱ�ɾ���Ľ���ҽ�㣬�ӵ��ú��ӽ����Һ��ӽ����
			if(maxChildFatherNode == NULL) {

				imBalanceNode = childNode;

				TreeNode* targetRightNode = targetNode->rightLeaf;
				targetRightNode->father = childNode;
				childNode->rightLeaf = targetRightNode;

				childNode->father = targetFatherNode;
				if(isLeft) {
					targetFatherNode->leftLeaf = childNode;
				} else {
					targetFatherNode->rightLeaf = childNode;
				}
				delete targetNode;
			} else {

				imBalanceNode = maxChildFatherNode;

				// ֱ�ӰѸý�㣬�嵽Ҫɾ������λ��
				TreeNode* targetRightNode = targetNode->rightLeaf;
				targetRightNode->father = childNode;
				childNode->rightLeaf = targetRightNode;

				TreeNode* targetLeftNode = targetNode->leftLeaf;
				targetLeftNode->father = childNode;
				childNode->leftLeaf = targetLeftNode;

				// ����Ҫע�⣺������Ľ�㣬���ܻ��������ӽ��
				TreeNode* childLeftNode = childNode->leftLeaf;
				maxChildFatherNode->rightLeaf = childLeftNode;
				if(childLeftNode != NULL) {
					childLeftNode->father = maxChildFatherNode;
				}

				childNode->father = targetFatherNode;
				if(isLeft) {
					targetFatherNode->leftLeaf = childNode;
				} else {
					targetFatherNode->rightLeaf = childNode;
				}
				delete targetNode;
			}

		}
	}

	// ����һ�£���Ӱ��Ľ��
	while(imBalanceNode != NULL) {
		TreeNode* tempNode = imBalanceNode;

		int balanceFactor = getBalanceFactor(tempNode);

		if(abs(balanceFactor) > 1) {
			// ��ƽ��
			if(balanceFactor < 0) {
				// ��Ҫ����ת,���ж�LL RL
				if(getBalanceFactor(tempNode->rightLeaf)>0) {
					RL(tempNode,root);
				} else {
					LL(tempNode,root);
				}
			} else {
				// ��Ҫ����ת�����ж�RR LR
				if(getBalanceFactor(tempNode->leftLeaf) <0) {
					LR(tempNode,root);
				} else {
					RR(tempNode,root);
				}
			}
		}

		imBalanceNode = imBalanceNode->father;
	}

	std::cout << "�ɹ�ɾ����㣬staget = "<< target << std::endl;
}
