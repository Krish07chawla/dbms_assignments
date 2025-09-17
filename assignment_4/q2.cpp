#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == (rear + 1) % SIZE); }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is Full\n";
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
            cout << x << " enqueued\n";
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            cout << arr[front] << " dequeued\n";
            if (front == rear) front = rear = -1; // Queue becomes empty
            else front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            cout << "Queue: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.dequeue();
    cq.enqueue(50);
    cq.enqueue(60); // shows circular reuse
    cq.display();
    cq.peek();
}
