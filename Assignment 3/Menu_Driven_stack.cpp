#include <iostream>
using namespace std;

#define MAX 5   

int stackArr[MAX]; 
int top = -1;    

// Function to check if stack is full
bool isFull() {
    return (top == MAX - 1);
}

// Function to check if stack is empty
bool isEmpty() {
    return (top == -1);
}

// Push operation
void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        top++;
        stackArr[top] = value;
        cout << value << " pushed into stack.\n";
    }
}

// Pop operation
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop.\n";
    } else {
        cout << stackArr[top] << " popped from stack.\n";
        top--;
    }
}

// Peek / Top element
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element is: " << stackArr[top] << endl;
    }
}

// Display stack contents
void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
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
