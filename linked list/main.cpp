#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

void insertNode(int value);

void deleteNode(int value);

void insert_beg(int value);

void delete_beg();

void delete_end();

void display();



int main() {

    insertNode(10);
    insertNode(5);
    insertNode(3);
    insertNode(15);
    insertNode(0);

    display();

    deleteNode(15);

    display();

    insert_beg(15);

    display();

    delete_beg();

    display();

    delete_end();

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

    cout << endl;
}


void deleteNode(int value) {
    node * current, * previous;

    current = head;
    previous = head;

    if(current->data == value) {
        head = current->next;
        delete(current);
        return;
    }

    while(current->data != value) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    delete(current);
}

void insert_beg(int value) {
    node * new_node = new node;

    new_node->data = value;
    new_node->next = head;
    head = new_node;
}


void delete_beg() {
    if(head == NULL) {
        cout << "Linked list is empty.";
    } else {
        node * first_node = head;
        head = first_node->next;
        delete(first_node);
    }
}


void delete_end() {
    if(head == NULL) {
        cout << "Linked list is empty.";
    } else if(head->next == NULL) {
        delete(head);
        head = NULL;
    } else {
        node * ptr = head;
        while(ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        delete(ptr->next);
        ptr->next = NULL;
    }
}