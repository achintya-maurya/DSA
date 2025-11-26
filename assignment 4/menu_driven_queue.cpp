#include <iostream>
using namespace std;

#define MAX 5   

int queueArr[MAX]; 
int front = -1, rear = -1; 
bool isFull() {
    return (rear == MAX - 1);
}
bool isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot enqueue " << value << endl;
    } else {
        if (front == -1) front = 0;  // first element
        rear++;
        queueArr[rear] = value;
        cout << value << " enqueued into queue.\n";
    }
}
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue.\n";
    } else {
        cout << queueArr[front] << " dequeued from queue.\n";
        front++;
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Front element is: " << queueArr[front] << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++) {
            cout << queueArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
