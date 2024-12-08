#include "../include/queue.h"

queue::queue() {
	capacity = 0;
	front = size = 0;
	rear = capacity - 1;
	q = nullptr;
}

queue::queue(int capacity1) {
	capacity = capacity1;
	front = size = 0;
	rear = 0;
	q = new double[capacity];
}

queue::~queue() {
	delete[]q;
}

bool queue::isFull() {
	return (size == capacity);
}

bool queue::isEmpty() {
	return(size == 0);
}

void queue::enQueue(double x) {
	if (!isFull()) {
		q[rear] = x;
		rear = (rear + 1) % capacity;
		size = size + 1;
	}
	else {
		std::cout << "queue is full" << std::endl;
	}
}

double queue::deQueue() {
	if (isEmpty()) {
		return INT_MIN;
	}
	double item = q[front];
	front = (front + 1) % capacity;
	size = size - 1;
	return item;
}

double queue::first() {
	if (isEmpty()) {
		return INT_MIN;
	}
	return q[front];
}

double queue::last() {
	if (isEmpty()) {
		return INT_MIN;
	}
	return q[rear];
}
