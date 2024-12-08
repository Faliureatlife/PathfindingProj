#include <iostream>
#include <climits>

#pragma once
class queue {
private:
	int front, rear, size;
	int capacity;
	double* q;
public:
	queue();
	queue(int capacity1);
	~queue();

	bool isFull();
	bool isEmpty();

	void enQueue(double x);
	double deQueue();

	double first();
	double last();
};
