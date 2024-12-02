class Queue {
private:
	int front, rear, size;
	int capacity;
	double* q;
public:
	Queue() {
		capacity = 0;
		front = size = 0;
		rear = capacity - 1;
		q = nullptr;
	}
	Queue(int capacity1) {
		capacity = capacity1;
		front = size = 0;
		rear = 0;
		q = new double[capacity];
	}
	~Queue() {
		delete[]q;
	}
	bool IsFull() {
		return (size == capacity);
	}
	bool IsEmpty() {
		return(size == 0);
	}
	void Enqueue(double x) {
		if (!IsFull()) {
			q[rear] = x;
			rear = (rear + 1) % capacity;
			size = size + 1;
		}
		else {
			cout << "Queue is full" << endl;
		}
	}
	double Dequeue() {
		if (IsEmpty()) {
			return INT_MIN;
		}
		double item = q[front];
		front = (front + 1) % capacity;
		size = size - 1;
		return item;
	}
	double Front() {
		if (IsEmpty()) {
			return INT_MIN;
		}
		return q[front];
	}
	double Rear() {
		if (IsEmpty()) {
			return INT_MIN;
		}
		return q[rear];
	}
};