#include "linkedlist.h"

void LinkedList::addRoot(LinkedListNode* node) {

	LinkedListRootNode* rootNode = (LinkedListRootNode*)malloc(sizeof(LinkedListRootNode));

	rootNode->root = node;
	rootNode->tail = LinkedListRootNodeNull;

	if(sum == 0) {
		root = rootNode;
		tail = rootNode;
	} else {
		tail->tail = rootNode;
		tail = rootNode;
	}
	sum++;

}

void LinkedList::deleteRoot(LinkedListNode* node) {

	// ��ǰ�ҵ��ڵ�
	LinkedListRootNode* temp =  LinkedListRootNodeNull;

	// �ҵ��ڵ�ĸ��ڵ�
	LinkedListRootNode* tempLast = LinkedListRootNodeNull;


	temp = root;

	while(temp->root->c != node->c) {

		tempLast = temp;
		temp = tempLast->tail;

	}



	// ����ǵ�һ��
	if(tempLast == LinkedListRootNodeNull ) {

		// ���ֻ��һ��
		if(sum == 1) {
			root =  LinkedListRootNodeNull;
			tail = LinkedListRootNodeNull;
		} else {
			root =  temp->tail;
		}
	} else {

		// ��������һ��
		if(tail == temp) {
			tempLast->tail = LinkedListRootNodeNull;
			tail = tempLast;
		} else {
			tempLast->tail = temp->tail;
		}

	}

	delete(temp);
	sum--;
}

void linkedListAdd(LinkedListNode* root,LinkedListNode* newNode) {

	LinkedListNode* temp = root;

	while(temp->tail != LinkedListNodeNull) {
		temp = temp->tail;
	}

	temp->tail = newNode;
}

bool linkedListContain(LinkedListNode* root,char target) {
	LinkedListNode* temp = root;

	do {
		if(temp->c == target) {
			return true;
		}

		temp = temp->tail;

	}while(temp != LinkedListNodeNull);

	return false;
}
