
struct Data {
	int index;
	double value;
};

class PriorityQueue {
private:
	void minHeapify(int i, int size) {
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
			swap(queue[i], queue[smallest]);
			minHeapify(smallest, size);
		}
	}
	int capacity;
	int elements;
	Data* queue;
public:
	PriorityQueue() {
		capacity = 0;
		elements = 0;
		queue = nullptr;
	}
	PriorityQueue(int c) {
		capacity = c;
		elements = 0;
		queue = new Data[capacity];
	}
	~PriorityQueue() {
		delete[] queue;
	}
	int GetElems() {
		return elements;
	}
	bool IsEmpty() {
		return (elements == 0);
	}
	bool IsFull() {
		return (elements == capacity);
	}
	int GetParent(int child) {
		if (child % 2 == 0) {
			return (child / 2) - 1;
		}
		else {
			return child / 2;
		}
	}
	int GetLeftChild(int parent) {
		return (2 * parent + 1);
	}
	int GetRightChild(int parent) {
		return (2 * parent + 2);
	}
	void Push(int index, double value) {
		if (elements < capacity) {
			Data x;
			x.index = index;
			x.value = value;
			int i = elements;
			while ((i != 0) && (x.value < queue[i / 2].value)) {
				queue[i] = queue[i / 2];
				i /= 2;
			}
			queue[i] = x;
			elements++;
			cout << "Added (" << index << "," << value << ") size = " << elements
				<< endl;
		}
		else {
			cout << "Out of Capacity" << endl;
		}
	}
	Data Pop() {
		if (elements > 0) {
			Data temp = queue[0];
			queue[0] = queue[elements - 1];
			minHeapify(0, elements);
			elements--;
			return temp;
		}
		else {
			Data temp;
			temp.value = 0;
			temp.index = -1;
			return temp;
		}
	}
	void DecreaseKey(int index, double value) {
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
			int parent = GetParent(child);
			while ((queue[child].value < queue[parent].value) && (child >= 0 &&
				parent >= 0)) {
				swap(queue[child], queue[parent]);
				child = parent;
				parent = GetParent(child);
			}
		}
	}
	void BuildMinHeap() {
		for (int i = elements / 2 - 1; i >= 0; i--) {
			minHeapify(i, elements);
		}
	}
	void Display() {
		cout << "Priority Queue" << endl;
		cout << "\t capacity: " << capacity << endl;
		cout << "\t elements: " << elements << endl;
		for (int i = 0; i < elements; i++) {
			cout << i << ": (" << queue[i].index << "," << queue[i].value << ")" <<
				endl;
		}
		cout << endl;
	}
};