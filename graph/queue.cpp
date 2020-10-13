#include "queue.h"

Queue::Queue() {
	head = NODE_NULL;
	tail = NODE_NULL;
}

Queue::~Queue() {
	head = NODE_NULL;
	tail = NODE_NULL;
}

void Queue::enqueue(QueueNode* node) {
	if(tail != NODE_NULL) {
		tail->next = node;
		tail = node;
	} else {
		head = tail = node;
	}
}

QueueNode* Queue::poll() {
	QueueNode* result = head;
	if(head != NODE_NULL) {
		if(head->next != NODE_NULL) {
			head = head->next;
		} else {
			head = tail = NODE_NULL;
		}
	}
	return result;
}
