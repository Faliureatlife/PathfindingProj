
#include <iostream>
#pragma once
struct data {
	int index;
	double value;
};

#pragma once
class priorityQueue {
private:
	void minHeapify(int i, int size);
	int capacity;
	int elements;
	data* queue;
public:
	priorityQueue();
	priorityQueue(int c);
	~priorityQueue();

	int getElems();

	bool isEmpty();
	bool isFull();

	int getParent(int child);
	int getLeftChild(int parent);
	int getRightChild(int parent);

	void push(int index, double value);
	data pop();

	void decreaseKey(int index, double value);
	void buildMinHeap();
	void display();
};
