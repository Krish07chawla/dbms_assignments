#include <iostream>
using namespace std;

#define SIZE 5

class SimpleQueue {
    int arr[SIZE];
    int front, rear;
public:
    SimpleQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is Full\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
            cout << x << " enqueued\n";
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << arr[front++] << " dequeued\n";
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    SimpleQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.peek();
    
    q.display();
}
