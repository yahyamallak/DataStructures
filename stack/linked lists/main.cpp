#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

node* top = NULL;

void push(int value);

int pop();

int peek();

void display();



int main() {

    push(5);
    push(10);
    push(3);
    push(0);
    push(8);

    display();

    pop();

    display();

    cout << peek();

    return 0;
}


void display() {
    node* currentNode;

    if(top == NULL) {
        cout << "Stack is empty.";
    } else {
        currentNode = top;
        while(currentNode != NULL) {
            cout << currentNode->data << "\n";
            currentNode = currentNode->next;
        }
    }

    cout << endl;
}


void push(int value) {
    node * new_node = new node;

    new_node->data = value;
    new_node->next = top;
    top = new_node;
}


int pop() {
    int value;
    if(top == NULL) {
        cout << "Stack is empty.";
        return -1;
    } else {
        node * first_node = top;
        top = first_node->next;
        value = first_node->data;
        delete(first_node);
        return value;
    }
}

int peek() {
    if(top == NULL) {
        cout << "Stack is empty.";
        return -1;
    } else {
        return top->data;
    }
}