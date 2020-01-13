/*
	Name:
	Copyright:
	Author:
	Date: 13/01/20 12:14
	Description: ����������
	��1����ӡ
	��2������
	��3������
	��4����ø߶�
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<stdlib.h>
#include <iostream>
#include<algorithm>

struct TreeNode {
	TreeNode* leftLeaf;
	TreeNode* rightLeaf;
	TreeNode* father;
	int data;
};

// ��ӡ��
void print(TreeNode**,int);

// ����
void find(TreeNode**,int,int);

// �������ֵ
void findMax(TreeNode**);

// ������Сֵ
void findMin(TreeNode**);

// ���� ��L��������  ��D�������   ��R��������
// LDR
void traversalLDR(TreeNode**);

// DLR
void traversalDLR(TreeNode**);

// RDL
void traversalRDL(TreeNode**);

// ������ĸ߶�
int getTreeHeight(TreeNode*);

#endif
