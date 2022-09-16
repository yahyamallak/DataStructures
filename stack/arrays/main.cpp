// Stack implementation using Arrays

#include <iostream>

using namespace std;

#define SIZE 5 

int stack[SIZE], top = -1;

void push(int value);

int pop();

int peek();

void display();

int main() {

    display();

    push(10);
    push(5);
    push(3);
    push(15);
    push(0);

    display();

    pop();

    display();

    cout << peek();

    return 0;
}


void push(int value) {
    if(top == SIZE - 1) {
        cout << "Stack is full." << endl;
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if(top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        return stack[top--];
    }
}

int peek() {
    if(top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        return stack[top];
    }
}

void display() {
    if(top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        for(int i=top; i>=0; i--) {
            cout << stack[i] << endl;
        }
    }
}