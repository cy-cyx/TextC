#ifndef QUEUE_H

#define QUEUE_H

#define NODE_NULL ((Node*)0)

struct Node {
	Node *next;
	char c;
	char last;
};

class Queue {

	public:
		Node *head;
		Node *tail;
		Queue();
		~Queue();
		void enqueue(Node*);
		Node* poll();
};

#endif
