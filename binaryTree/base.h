#ifndef BASE_H
#define BASE_H

#include<stdlib.h>
#include <iostream>

struct TreeNode {
	TreeNode* leftLeaf;
	TreeNode* rightLeaf;
	TreeNode* father;
	int data;
};

// ����(���������������˳������
void insert(TreeNode**,int);

// ��ӡ��
void print(TreeNode**,int);

// ����
void find(TreeNode**,int,int);

// �������ֵ
void findMax(TreeNode**);

// ������Сֵ
void findMin(TreeNode**);

// ɾ��ָ����Ҷ
void deleteLeaf(TreeNode**,int);

#endif
