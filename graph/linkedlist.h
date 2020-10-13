#ifndef LINKED_LIST_H

#define LINKED_LIST_H

#include <malloc.h>

#define LinkedListNodeNull (LinkedListNode*)0
#define LinkedListRootNodeNull (LinkedListRootNode*)0

// 用于记录一棵树
struct LinkedListNode {
	char c;
	LinkedListNode *tail;
};

// 用于记录树根
struct LinkedListRootNode {
	LinkedListNode *root;
	LinkedListRootNode* tail;
};

class LinkedList {

	public:
		int sum;  // 数量
		LinkedListRootNode *root;  // 根
		LinkedListRootNode *tail;  // 尾

		void addRoot(LinkedListNode*);
		void deleteRoot(LinkedListNode*);
};

// 向已知的链表表中加入新的节点或者链表
void linkedListAdd(LinkedListNode*,LinkedListNode*);

// 判断链表中没有该节点
bool linkedListContain(LinkedListNode*,char);

#endif
