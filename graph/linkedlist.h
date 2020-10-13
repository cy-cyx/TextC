#ifndef LINKED_LIST_H

#define LINKED_LIST_H

#include <malloc.h>

#define LinkedListNodeNull (LinkedListNode*)0
#define LinkedListRootNodeNull (LinkedListRootNode*)0

// ���ڼ�¼һ����
struct LinkedListNode {
	char c;
	LinkedListNode *tail;
};

// ���ڼ�¼����
struct LinkedListRootNode {
	LinkedListNode *root;
	LinkedListRootNode* tail;
};

class LinkedList {

	public:
		int sum;  // ����
		LinkedListRootNode *root;  // ��
		LinkedListRootNode *tail;  // β

		void addRoot(LinkedListNode*);
		void deleteRoot(LinkedListNode*);
};

// ����֪��������м����µĽڵ��������
void linkedListAdd(LinkedListNode*,LinkedListNode*);

// �ж�������û�иýڵ�
bool linkedListContain(LinkedListNode*,char);

#endif
