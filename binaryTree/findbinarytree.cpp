#include "findbinarytree.h"

void insert(TreeNode** node,int data) {

	// �����Ϊ��,�ͷ��ں��ӽ���λ�ü���
	if(*node == NULL) {
		*node = (TreeNode*)malloc(sizeof(TreeNode));
		(*node)->leftLeaf = NULL;
		(*node)->rightLeaf = NULL;
		(*node)->data = data;
	}
	// �����㲻Ϊ�գ��������ӽ��ĺ��ӽ���������ȥ�����յݹ�
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

	// ���Ϊ�գ���ʾ�ս��
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
		// �ȴ�ӡ���ӽ��
		print(&(*node)->leftLeaf,level+1);

		// ��ӡ�Լ�
		for(int i = 0; i < level; i++) {
			std::cout << "  ";
		}
		for(int i = 0; i < level; i++) {
			std::cout << "_";
		}
		std::cout <<level<<"_"<< (*node)->data << std::endl;

		// ��ӡ�Һ��ӽ��
		print(&(*node)->rightLeaf,level+1);
	}
}

void find(TreeNode** node,int target,int time) {
	// �ҵ���ӡ����
	if((*node)->data == target) {
		std::cout << "find target:"<<target<<",time is "<<time<<std::endl;
	} else {
		// ��Ŀ��С��������ӽ���оͼ����ң�û�о�����
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
	// ����Һ��ӽ��Ϊ��ʱ����˵����������ˣ���Ȼ�ͼ�����
	if((*node)->rightLeaf == NULL) {
		std::cout << "max leaf is "<<(*node)->data<<std::endl;
	} else {
		findMax(&(*node)->rightLeaf);
	}
}

void findMin(TreeNode** node) {
	// ������ӽ��Ϊ��ʱ����˵��������С�ˣ���Ȼ�ͼ�����
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

	// �Ҷ�Ӧ�Ľ����жϸý��ĸ�������Ϊ��˵�����ý��Ϊ��
	if(targetFatherNode == NULL) {
		// ����Ǹ�

		// ���1��û�к��ӽ�㣬ֱ���ÿո�
		if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf ==NULL) {
			// ����ע��Ҫ�����ڴ�
			delete *root;
			*root = NULL;
		}
		// ���2��3��������ҽ���һ�����ӽ��
		else if(targetNode->leftLeaf != NULL&&targetNode->rightLeaf == NULL) {
			TreeNode* tempNode = targetNode->leftLeaf;
			delete *root;
			*root  = tempNode;
		} else if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf != NULL) {
			TreeNode* tempNode = targetNode->rightLeaf;
			delete *root;
			*root  = tempNode;
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
				childNode->rightLeaf = (*root)->rightLeaf;
				delete *root;
				*root  = childNode;
			} else {

				// ֱ�ӰѸý�㣬�嵽Ҫɾ������λ��
				childNode->rightLeaf = (*root)->rightLeaf;

				// ����Ҫע�⣺������Ľ�㣬���ܻ��������ӽ��
				maxChildFatherNode->rightLeaf = childNode->leftLeaf;
				childNode->leftLeaf = (*root)->leftLeaf;
				delete *root;
				*root  = childNode;
			}

		}
	} else {
		// ���1������ýڵ�û�к��ӽ��
		if(targetNode->leftLeaf == NULL&&targetNode->rightLeaf == NULL) {
			if(isLeft) {
				targetFatherNode->leftLeaf = NULL;
			} else {
				targetFatherNode->rightLeaf = NULL;
			}
			delete targetNode;
		}
		// ���2��3�����ҽ���һ�����ӽ��
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
				childNode->rightLeaf = targetNode->rightLeaf;
				if(isLeft) {
					targetFatherNode->leftLeaf = childNode;
				} else {
					targetFatherNode->rightLeaf = childNode;
				}
				delete targetNode;
			} else {

				// ֱ�ӰѸý�㣬�嵽Ҫɾ������λ��
				childNode->rightLeaf = targetNode->rightLeaf;

				// ����Ҫע�⣺������Ľ�㣬���ܻ��������ӽ��
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

	std::cout << "�ɹ�ɾ����㣬staget = "<< target << std::endl;
}

void traversalLDR(TreeNode** root) {
	// �ȱ�������
	if((*root)->leftLeaf != NULL) {
		traversalLDR(&(*root)->leftLeaf);
	}

	// ��ӡ��
	std::cout<<(*root)->data<<" ";

	// ��������
	if((*root)->rightLeaf != NULL) {
		traversalLDR(&(*root)->rightLeaf);
	}
}

void traversalRDL(TreeNode** root) {
	// ����
	if((*root)->rightLeaf != NULL) {
		traversalRDL(&(*root)->rightLeaf);
	}

	// ��ӡ��
	std::cout<<(*root)->data<<" ";

	// ����
	if((*root)->leftLeaf != NULL) {
		traversalRDL(&(*root)->leftLeaf);
	}
}

