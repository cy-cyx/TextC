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

void delete_balance(TreeNode** root,int target) {

	TreeNode* imBalanceNode;

	// 延用查找二叉树的删除逻辑，在删除后进行遍历平衡操作
	TreeNode* targetNode = NULL;
	TreeNode* targetFatherNode = NULL;
	bool isLeft = false;

	// 先找出对应的结点
	targetNode = *root;

	while(targetNode->data != target) {
		targetFatherNode = targetNode;

		// 继续往孩子结点找
		TreeNode* tempNode;
		if(target < targetNode->data) {
			isLeft = true;
			tempNode =  targetNode->leftLeaf;
		} else {
			isLeft = false;
			tempNode = targetNode->rightLeaf;
		}
		// 如果接下的孩子结点没有的话，说明树中没有这个结点
		if(tempNode == NULL) {
			std::cout<<"delete : no this leaf"<<target<<std::endl;
			return;
		} else {
			targetNode = tempNode;
		}
	}

	// 找对应的结点后，判断该结点的父结点如果为空说明该结点为根
	if(targetFatherNode == NULL) {
		// 如果是根

		// 情况1，没有孩子结点，直接置空根
		if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf ==NULL) {
			// 这里注意要回收内存
			*root = NULL;
			delete targetNode;

			std::cout << "成功删除结点，staget = "<< target << std::endl;
			return;
		}
		// 情况2、3，如果有且仅有一个孩子结点
		else if(targetNode->leftLeaf != NULL&&targetNode->rightLeaf == NULL) {
			TreeNode* tempNode = targetNode->leftLeaf;
			tempNode->father = NULL;
			*root  = tempNode;
			delete targetNode;

			std::cout << "成功删除结点，staget = "<< target << std::endl;
			return;
		} else if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf != NULL) {
			TreeNode* tempNode = targetNode->rightLeaf;
			tempNode->father = NULL;
			*root  = tempNode;
			delete targetNode;

			std::cout << "成功删除结点，staget = "<< target << std::endl;
			return;
		}
		// 情况4，两个孩子结点都在，找左孩子结点中的最大去作为根
		else {
			TreeNode* maxChildFatherNode = NULL;
			TreeNode* childNode = targetNode->leftLeaf;
			// 找左孩子结点（树）中最大的结点
			while(childNode->rightLeaf != NULL) {
				maxChildFatherNode = childNode;
				childNode = childNode->rightLeaf;
			}

			// 如果最大结点是左孩子结点自己（即右结点为空），就把删除的结点右结点，接到该孩子结点的右孩子结点上
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

				// 直接把该结点，插到要删除结点的位置
				TreeNode* targetRightNode = targetNode->rightLeaf;
				targetRightNode->father = childNode;

				childNode->rightLeaf = targetRightNode;

				TreeNode* targetLeftNode = targetNode->leftLeaf;
				targetLeftNode->father = childNode;

				childNode->leftLeaf = targetLeftNode;

				// 这里要注意：这个最大的结点，可能还存在左孩子结点
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
		// 情况1，如果该节点没有孩子结点
		if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf == NULL) {

			imBalanceNode = targetFatherNode;

			if(isLeft) {
				targetFatherNode->leftLeaf = NULL;
			} else {
				targetFatherNode->rightLeaf = NULL;
			}
			delete targetNode;
		}
		// 情况2、3，有且仅有一个孩子结点
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
		// 情况4，左右结点都在
		else {

			TreeNode* maxChildFatherNode = NULL;
			TreeNode* childNode = targetNode->leftLeaf;

			while(childNode->rightLeaf != NULL) {
				maxChildFatherNode = childNode;
				childNode = childNode->rightLeaf;
			}

			// 如果最大结点是左孩子结点自己（即右结点为空），就把删除的结点右结点，接到该孩子结点的右孩子结点上
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

				// 直接把该结点，插到要删除结点的位置
				TreeNode* targetRightNode = targetNode->rightLeaf;
				targetRightNode->father = childNode;
				childNode->rightLeaf = targetRightNode;

				TreeNode* targetLeftNode = targetNode->leftLeaf;
				targetLeftNode->father = childNode;
				childNode->leftLeaf = targetLeftNode;

				// 这里要注意：这个最大的结点，可能还存在左孩子结点
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

	// 遍历一下，受影响的结点
	while(imBalanceNode != NULL) {
		TreeNode* tempNode = imBalanceNode;

		int balanceFactor = getBalanceFactor(tempNode);

		if(abs(balanceFactor) > 1) {
			// 不平衡
			if(balanceFactor < 0) {
				// 需要左旋转,再判断LL RL
				if(getBalanceFactor(tempNode->rightLeaf)>0) {
					RL(tempNode,root);
				} else {
					LL(tempNode,root);
				}
			} else {
				// 需要右旋转，再判断RR LR
				if(getBalanceFactor(tempNode->leftLeaf) <0) {
					LR(tempNode,root);
				} else {
					RR(tempNode,root);
				}
			}
		}

		imBalanceNode = imBalanceNode->father;
	}

	std::cout << "成功删除结点，staget = "<< target << std::endl;
}
