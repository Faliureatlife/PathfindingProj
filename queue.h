class queue {
private:
	int front, rear, size;
	int capacity;
	double* q;
public:
	queue() {
		capacity = 0;
		front = size = 0;
		rear = capacity - 1;
		q = nullptr;
	}
	queue(int capacity1) {
		capacity = capacity1;
		front = size = 0;
		rear = 0;
		q = new double[capacity];
	}
	~queue() {
		delete[]q;
	}
	bool isFull() {
		return (size == capacity);
	}
	bool isEmpty() {
		return(size == 0);
	}
	void enQueue(double x) {
		if (!isFull()) {
			q[rear] = x;
			rear = (rear + 1) % capacity;
			size = size + 1;
		}
		else {
			std::cout << "queue is full" << std::endl;
		}
	}
	double deQueue() {
		if (isEmpty()) {
			return INT_MIN;
		}
		double item = q[front];
		front = (front + 1) % capacity;
		size = size - 1;
		return item;
	}
	double first() {
		if (isEmpty()) {
			return INT_MIN;
		}
		return q[front];
	}
	double last() {
		if (isEmpty()) {
			return INT_MIN;
		}
		return q[rear];
	}
};
