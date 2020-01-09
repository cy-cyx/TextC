/*
	Name:
	Copyright:
	Author:
	Date: 09/01/20 16:53
	Description: 二叉查找树\二叉顺序树
	  1、插入
	  2、查找
	  3、打印  打印树状图
	  4、删除
	  5、遍历 LDR(从小到大排序) LDR（从大到小排序）
*/
#ifndef FINDBINARYTREE_H
#define FINDBINARYTREE_H

#include<stdlib.h>
#include <iostream>

struct TreeNode {
	TreeNode* leftLeaf;
	TreeNode* rightLeaf;
	TreeNode* father; // 未使用
	int data;
};

// 插入(二叉查找树、二叉顺序树）
void insert(TreeNode**,int);

// 打印树
void print(TreeNode**,int);

// 查找
void find(TreeNode**,int,int);

// 查找最大值
void findMax(TreeNode**);

// 查找最小值
void findMin(TreeNode**);

// 删除指定子叶
void deleteLeaf(TreeNode**,int);

// 遍历 （L）左子树  （D）根结点   （R）右子树
// LDR
void traversalLDR(TreeNode**);

// DLR
void traversalDLR(TreeNode**);

// RDL
void traversalRDL(TreeNode**);

#endif
