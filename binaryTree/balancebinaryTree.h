/*
	Name:
	Copyright:
	Author:
	Date: 13/01/20 12:19
	Description: 平衡二叉树（所有结点平衡系数仅可以为 1，0，-1）
*/

#ifndef BALANCEBINARYTREE_H
#define BALANCEBINARYTREE_H

#include"binarytree.h"

// 平衡二叉树插入后 要判断是否影响了二叉树平衡性，如果影响了平衡性，
// 只要恢复最近的不平衡二叉树，即可恢复整棵树的平衡性。
// 理由：恢复了最近的不平衡二叉树，即恢复该子树原先的高度，且该子树就恢复平衡，所以整棵树就恢复平衡了
// 恢复子树的方法有四种：LL RR LR RL
void insert_balance(TreeNode**,int);

// 平衡二叉树删除后 要从删除的结点或者用于替换的结点的双亲结点开始遍历判断平衡性
// 由于与添加结点不同，删除结点后最近的不平衡二叉树高度是减少的，恢复平衡后，不一定是恢复原先的高度，
// 故选择遍历的方法，保证可能受影响的枝干都恢复成平衡结点
void delete_balance(TreeNode**,int);

#endif
