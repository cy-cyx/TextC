#ifndef QUEUE_H

#define QUEUE_H

#define NODE_NULL ((QueueNode*)0)

struct QueueNode {
	QueueNode *next;
	char c;
	char last;  // ¸ù
};

class Queue {

	public:
		QueueNode *head;
		QueueNode *tail;
		Queue();
		~Queue();
		void enqueue(QueueNode*);
		QueueNode* poll();
};


#endif
