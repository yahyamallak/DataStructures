#include <iostream>

using namespace std;

#define SIZE 5

int queue[SIZE];

int front = -1, rear = -1;

bool isEmpty();

bool isFull();

void enqueue(int value);

void dequeue();

int peek();

void display();



int main() {

    enqueue(1);
    enqueue(9);
    enqueue(6);
    enqueue(7);
    enqueue(10);

    display();

    dequeue();

    display();

    enqueue(3);
    enqueue(5);

    display();

    return 0;
}


bool isEmpty() {
    if(front == -1 && rear == -1) {
        return true;
    } else {
        return false;
    }
}

bool isFull() {
    if(front == 0 && rear == SIZE - 1) {
        return true;
    } else if(rear == front - 1) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int value) {
    if(isFull()) {
        cout << "Queue is full." << endl;
    } else {
        if(isEmpty()) {
            front = rear = 0;
            queue[rear] = value;
        } else if(rear == SIZE - 1) {
            rear = 0;
            queue[rear] = value;
        } else {
            queue[++rear] = value;
        }
    }
}

void dequeue() {
    if(isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        if(front == rear) {
            front = rear = -1;
        } else if(front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}


int peek() {
    if(isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    if(isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        if(front <= rear) {
            for(int i = front; i <= rear; i++) {
                cout << queue[i] << "\t";
            }
            cout << endl;
        } else {
            for(int i = front; i < SIZE; i++) {
                cout << queue[i] << "\t";
            }

            for(int i = 0; i <= rear; i++) {
                cout << queue[i] << "\t";
            }
            cout << endl;
        }
    }
}