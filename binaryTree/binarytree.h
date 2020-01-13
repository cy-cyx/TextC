/*
	Name:
	Copyright:
	Author:
	Date: 13/01/20 12:14
	Description: 基本二叉树
	（1）打印
	（2）查找
	（3）遍历
	（4）获得高度
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

// 打印树
void print(TreeNode**,int);

// 查找
void find(TreeNode**,int,int);

// 查找最大值
void findMax(TreeNode**);

// 查找最小值
void findMin(TreeNode**);

// 遍历 （L）左子树  （D）根结点   （R）右子树
// LDR
void traversalLDR(TreeNode**);

// DLR
void traversalDLR(TreeNode**);

// RDL
void traversalRDL(TreeNode**);

// 获得树的高度
int getTreeHeight(TreeNode*);

#endif
