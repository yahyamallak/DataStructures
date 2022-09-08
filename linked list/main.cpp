#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

void insertNode(int value);

void display();



int main() {

    insertNode(10);
    insertNode(5);
    insertNode(3);
    insertNode(15);
    insertNode(0);

    display();

    return 0;
}

void insertNode(int value) {
    node* newNode, *last;

    newNode = new node;
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
        newNode->next = NULL;
    } else {
        last = head;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = NULL;
    }
}


void display() {
    node* currentNode;

    if(head == NULL) {
        cout << "Linked list is empty.";
    } else {
        currentNode = head;
        while(currentNode != NULL) {
            cout << currentNode->data << "\t";
            currentNode = currentNode->next;
        }
    }
}