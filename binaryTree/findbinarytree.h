/*
	Name:
	Copyright:
	Author:
	Date: 09/01/20 16:53
	Description: ���������\����˳����
	  1������
	  2������
	  3����ӡ  ��ӡ��״ͼ
	  4��ɾ��
	  5������ LDR(��С��������) LDR���Ӵ�С����
*/
#ifndef FINDBINARYTREE_H
#define FINDBINARYTREE_H

#include<stdlib.h>
#include <iostream>

struct TreeNode {
	TreeNode* leftLeaf;
	TreeNode* rightLeaf;
	TreeNode* father; // δʹ��
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

// ���� ��L��������  ��D�������   ��R��������
// LDR
void traversalLDR(TreeNode**);

// DLR
void traversalDLR(TreeNode**);

// RDL
void traversalRDL(TreeNode**);

#endif
