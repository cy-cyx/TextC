/*
	Name:
	Copyright:
	Author:
	Date: 13/01/20 12:19
	Description: ƽ������������н��ƽ��ϵ��������Ϊ 1��0��-1��
*/

#ifndef BALANCEBINARYTREE_H
#define BALANCEBINARYTREE_H

#include"binarytree.h"

// ƽ������������ Ҫ�ж��Ƿ�Ӱ���˶�����ƽ���ԣ����Ӱ����ƽ���ԣ�
// ֻҪ�ָ�����Ĳ�ƽ������������ɻָ���������ƽ���ԡ�
// ���ɣ��ָ�������Ĳ�ƽ������������ָ�������ԭ�ȵĸ߶ȣ��Ҹ������ͻָ�ƽ�⣬�����������ͻָ�ƽ����
// �ָ������ķ��������֣�LL RR LR RL
void insert_balance(TreeNode**,TreeNode*,int);

#endif
