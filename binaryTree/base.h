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

#endif
