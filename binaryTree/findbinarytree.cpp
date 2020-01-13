#include "findbinarytree.h"

void insertLeaf_find(TreeNode** node,int data) {
	// 若结点为空,就放在孩子结点的位置即可
	if(*node == NULL) {
		*node = (TreeNode*)malloc(sizeof(TreeNode));
		(*node)->leftLeaf = NULL;
		(*node)->rightLeaf = NULL;
		(*node)->father = NULL;
		(*node)->data = data;
	}
	// 如果结点不为空，就往孩子结点的孩子结点继续放下去，按照递归
	else {
		if(data < (*node)->data) {
			insertLeaf_find(&(*node)->leftLeaf,data);
		} else if(data > (*node)->data) {
			insertLeaf_find(&(*node)->rightLeaf,data);
		} else {
			std::cout <<"repeat target : "<< data << std::endl;
		}
	}
}

void deleteLeaf_find(TreeNode** root,int target) {

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
