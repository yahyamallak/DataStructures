#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

void insertNode(int value);

int main() {

    insertNode(10);

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