#include "base.h"

void insert(TreeNode** node,int data) {

	// ����ҶΪ��,�ͷ�����Ҷ��λ�ü���
	if(*node == NULL) {
		*node = (TreeNode*)malloc(sizeof(TreeNode));
		(*node)->leftLeaf = NULL;
		(*node)->rightLeaf = NULL;
		(*node)->data = data;
	}
	// �����Ҷ��Ϊ�գ�������Ҷ����Ҷ��������ȥ�����յݹ�
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

	// ���Ϊ�գ���ʾ����Ҷ
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
		// �ȴ�ӡ��ڵ�
		print(&(*node)->leftLeaf,level+1);

		// ��ӡ�Լ�
		for(int i = 0; i < level; i++) {
			std::cout << "  ";
		}
		for(int i = 0; i < level; i++) {
			std::cout << "_";
		}
		std::cout <<level<<"_"<< (*node)->data << std::endl;

		// ��ӡ�ҽڵ�
		print(&(*node)->rightLeaf,level+1);
	}
}

void find(TreeNode** node,int target,int time) {
	// �ҵ���ӡ����
	if((*node)->data == target) {
		std::cout << "find target:"<<target<<",time is "<<time<<std::endl;
	} else {
		// ��Ŀ��С���������Ҷ�оͼ����ң�û�о�����
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
	// �������ҶΪ��ʱ����˵����������ˣ���Ȼ�ͼ�����
	if((*node)->rightLeaf == NULL) {
		std::cout << "max leaf is "<<(*node)->data<<std::endl;
	} else {
		findMax(&(*node)->rightLeaf);
	}
}

void findMin(TreeNode** node) {
	// �������ҶΪ��ʱ����˵��������С�ˣ���Ȼ�ͼ�����
	if((*node)->leftLeaf == NULL) {
		std::cout << "min leaf is "<<(*node)->data<<std::endl;
	} else {
		findMin(&(*node)->leftLeaf);
	}
}

