#include "priorityQ.h"

void priorityQueue::minHeapify(int i, int size) {
	int left, right, smallest;
	left = 2 * i + 1;
	right = 2 * i + 2;
	smallest = i;
	if ((left < size) && (queue[left].value < queue[i].value)) {
		smallest = left;
	}
	if ((right < size) && (queue[right].value < queue[smallest].value)) {
		smallest = right;
	}
	if (smallest != i) {
		std::swap(queue[i], queue[smallest]);
		minHeapify(smallest, size);
	}
}

priorityQueue::priorityQueue() {
	capacity = 0;
	elements = 0;
	queue = nullptr;
}

priorityQueue::priorityQueue(int c) {
	capacity = c;
	elements = 0;
	queue = new data[capacity];
}

priorityQueue::~priorityQueue() {
	delete[] queue;
}

int priorityQueue::getElems() {
	return elements;
}
bool priorityQueue::isEmpty() {
	return (elements == 0);
}
bool priorityQueue::isFull() {
	return (elements == capacity);
}
int priorityQueue::getParent(int child) {
	if (child % 2 == 0) {
		return (child / 2) - 1;
	}
	else {
		return child / 2;
	}
}
int priorityQueue::getLeftChild(int parent) {
	return (2 * parent + 1);
}
int priorityQueue::getRightChild(int parent) {
	return (2 * parent + 2);
}
void priorityQueue::push(int index, double value) {
	if (elements < capacity) {
		data x;
		x.index = index;
		x.value = value;
		int i = elements;
		while ((i != 0) && (x.value < queue[i / 2].value)) {
			queue[i] = queue[i / 2];
			i /= 2;
		}
		queue[i] = x;
		elements++;
		std::cout << "Added (" << index << "," << value << ") size = " << elements
			<< std::endl;
	}
	else {
		std::cout << "Out of Capacity" << std::endl;
	}
}
data priorityQueue::pop() {
	if (elements > 0) {
		data temp = queue[0];
		queue[0] = queue[elements - 1];
		minHeapify(0, elements);
		elements--;
		return temp;
	}
	else {
		data temp;
		temp.value = 0;
		temp.index = -1;
		return temp;
	}
}
void priorityQueue::decreaseKey(int index, double value) {
	int i = 0;
	bool found = false;
	while ((!found) && (i < elements)) {
		if (queue[i].index == index) {
			queue[i].value = value;
			found = true;
		}
		i++;
	}
	if (found) {
		int child = -1;
		int parent = getParent(child);
		while ((queue[child].value < queue[parent].value) && (child >= 0 &&
			parent >= 0)) {
			std::swap(queue[child], queue[parent]);
			child = parent;
			parent = getParent(child);
		}
	}
}
void priorityQueue::buildMinHeap() {
	for (int i = elements / 2 - 1; i >= 0; i--) {
		minHeapify(i, elements);
	}
}
void priorityQueue::display() {
	std::cout << "Priority Queue" << std::endl;
	std::cout << "\t capacity: " << capacity << std::endl;
	std::cout << "\t elements: " << elements << std::endl;
	for (int i = 0; i < elements; i++) {
		std::cout << i << ": (" << queue[i].index << "," << queue[i].value << ")" <<
			std::endl;
	}
	std::cout << std::endl;
}