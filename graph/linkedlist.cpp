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

	// 当前找到节点
	LinkedListRootNode* temp =  LinkedListRootNodeNull;

	// 找到节点的父节点
	LinkedListRootNode* tempLast = LinkedListRootNodeNull;


	temp = root;

	while(temp->root->c != node->c) {

		tempLast = temp;
		temp = tempLast->tail;

	}



	// 如果是第一个
	if(tempLast == LinkedListRootNodeNull ) {

		// 如果只有一个
		if(sum == 1) {
			root =  LinkedListRootNodeNull;
			tail = LinkedListRootNodeNull;
		} else {
			root =  temp->tail;
		}
	} else {

		// 如果是最后一个
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
