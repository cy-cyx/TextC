#include"binarytree.h"

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
		if((*node)->father == NULL) {
			std::cout <<level<<"_"<< (*node)->data << std::endl;
		} else {
			std::cout <<level<<"_"<< (*node)->data << "_f = " <<(*node)->father->data<< std::endl;
		}

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

int getTreeHeight(TreeNode* node) {
	if(node == NULL) return 0;
	return(std::max(getTreeHeight(node->leftLeaf),getTreeHeight(node->rightLeaf)) + 1);
}
