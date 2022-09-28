#include <iostream>

using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value);

void dequeue();

int peek();

void display();

int main() {

    enqueue(10);
    enqueue(0);
    enqueue(5);
    enqueue(7);

    display();

    dequeue();

    display();

    cout << "peek = " << peek();

    return 0;
}


void enqueue(int value) {
    if(rear != SIZE - 1) {
        if(front == -1 && rear == -1) {
            front++;
            queue[++rear] = value;
        } else {
            queue[++rear] = value;
        }
    } else {
        cout << "Queue is full" << endl;
    }
}

void dequeue() {
    if((front != -1 && rear != -1) && front <= rear) {
        front++;
    } else {
        cout << "Queue is empty" << endl;
    }
}

int peek() {
    if((front != -1 && rear != -1) && front <= rear) {
        return queue[front];
    } else {
        cout << "Queue is empty" << endl;
        return -1;
    }
}

void display() {
    if((front != -1 && rear != -1) && front <= rear) {
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << "\t";
        }
        cout << endl;
    } else {
        cout << "Queue is empty" << endl;
    }
}