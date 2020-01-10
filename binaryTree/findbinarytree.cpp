#include "findbinarytree.h"

void insert(TreeNode** node,int data) {

	// 若结点为空,就放在孩子结点的位置即可
	if(*node == NULL) {
		*node = (TreeNode*)malloc(sizeof(TreeNode));
		(*node)->leftLeaf = NULL;
		(*node)->rightLeaf = NULL;
		(*node)->data = data;
	}
	// 如果结点不为空，就往孩子结点的孩子结点继续放下去，按照递归
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
		std::cout <<level<<"_"<< (*node)->data << std::endl;

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

void deleteLeaf(TreeNode** root,int target) {

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

	// 找对应的结点后，判断该结点的父结点如果为空说明，该结点为根
	if(targetFatherNode == NULL) {
		// 如果是根

		// 情况1，没有孩子结点，直接置空根
		if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf ==NULL) {
			// 这里注意要回收内存
			delete *root;
			*root = NULL;
		}
		// 情况2、3，如果有且仅有一个孩子结点
		else if(targetNode->leftLeaf != NULL&&targetNode->rightLeaf == NULL) {
			TreeNode* tempNode = targetNode->leftLeaf;
			delete *root;
			*root  = tempNode;
		} else if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf != NULL) {
			TreeNode* tempNode = targetNode->rightLeaf;
			delete *root;
			*root  = tempNode;
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
				childNode->rightLeaf = (*root)->rightLeaf;
				delete *root;
				*root  = childNode;
			} else {

				// 直接把该结点，插到要删除结点的位置
				childNode->rightLeaf = (*root)->rightLeaf;

				// 这里要注意：这个最大的结点，可能还存在左孩子结点
				maxChildFatherNode->rightLeaf = childNode->leftLeaf;
				childNode->leftLeaf = (*root)->leftLeaf;
				delete *root;
				*root  = childNode;
			}

		}
	} else {
		// 情况1，如果该节点没有孩子结点
		if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf == NULL) {
			if(isLeft) {
				targetFatherNode->leftLeaf = NULL;
			} else {
				targetFatherNode->rightLeaf = NULL;
			}
			delete targetNode;
		}
		// 情况2、3，有且仅有一个孩子结点
		else if(targetNode->leftLeaf != NULL&&targetNode->rightLeaf == NULL) {
			if(isLeft) {
				targetFatherNode->leftLeaf = targetNode->leftLeaf;
			} else {
				targetFatherNode->rightLeaf = targetNode->leftLeaf;
			}
			delete targetNode;
		} else if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf != NULL) {
			if(isLeft) {
				targetFatherNode->leftLeaf = targetNode->rightLeaf;
			} else {
				targetFatherNode->rightLeaf = targetNode->rightLeaf;
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
				childNode->rightLeaf = targetNode->rightLeaf;
				if(isLeft) {
					targetFatherNode->leftLeaf = childNode;
				} else {
					targetFatherNode->rightLeaf = childNode;
				}
				delete targetNode;
			} else {

				// 直接把该结点，插到要删除结点的位置
				childNode->rightLeaf = targetNode->rightLeaf;

				// 这里要注意：这个最大的结点，可能还存在左孩子结点
				maxChildFatherNode->rightLeaf = childNode->leftLeaf;
				childNode->leftLeaf = targetNode->leftLeaf;

				if(isLeft) {
					targetFatherNode->leftLeaf = childNode;
				} else {
					targetFatherNode->rightLeaf = childNode;
				}
				delete targetNode;
			}

		}
	}

	std::cout << "成功删除结点，staget = "<< target << std::endl;
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

