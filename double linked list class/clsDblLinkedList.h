#include <iostream>


using namespace std;



template <class T> class clsDblLinkedList {

    protected:

    int _Size = 0;

    public:

    class Node {

    public:

        Node * prev;
        T value;
        Node * next;
    };

    Node * head = NULL;


    void InsertAtBeginning(T value) {

        Node * newNode = new Node();

        newNode->prev = NULL;
        newNode->value = value;
        newNode->next = head;

        if(head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
        _Size++;
    }

    void PrintList() {

        Node * current = head;

        while(current != NULL) {
            cout << current->value << "  ";
            current = current->next;
        }

        cout << endl;
        delete current;
    }

    Node * find(T value) {

        Node * current = head;

        while(current != NULL) {
            
            if(current->value == value)
                return current;
            
            current = current->next;
        }

        return NULL;
    }

    void InsertAfter(Node * current,T value) {

        Node * newNode = new Node();

        newNode->prev = current;
        newNode->value = value;
        newNode->next = current->next;

        if(current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;
        _Size++;
    }


    void InsertAtEnd(T value) {

        Node * newNode = new Node();

        newNode->next = NULL;
        newNode->value = value;

        if(head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node * current = head;
            while(current->next != NULL) {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
        }

        _Size++;
    }

    void DeleteNode(Node * & nodeToDelete) {

        if(head == NULL || nodeToDelete == NULL) {
            return;
        }

        if(head == nodeToDelete) {
            head = nodeToDelete->next;
        }

        if(nodeToDelete->next != NULL) {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        if(nodeToDelete->prev != NULL) {
            nodeToDelete->prev->next = nodeToDelete->next;
        }


        delete nodeToDelete;
        _Size--;
    }

    void DeleteFirstNode() {
        
        if(head == NULL) {
            return;
        }

        Node * temp = head;
        head = head->next;

        if(head != NULL) {
            head->prev = NULL;
        }

        delete temp;
        _Size--;
    }

    void DeleteLastNode() {

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;

        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;
    }

    int Size() {

        return _Size;
    }

    bool isEmpty() {
        return (_Size == 0);
    }

    void Clear() {
        while(_Size > 0) {
            DeleteFirstNode();
        }
    }

    void Reverse() {

        Node * current = head;
        Node * temp = nullptr;

        while(current != NULL) {

            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;

        }

        if(temp != nullptr) {
            head = temp->prev;
        }
    }

    Node * GetNode(int index) {

        if(index < 0) {
            cout << "incorrect index." << endl;
            return NULL;
        }

        if(isEmpty()) {
            cout << "Empty list." << endl;
            return NULL;
        }

        if(index > (_Size - 1)) {
            cout << "index not found." << endl;
            return NULL;
        }

        Node * current = head;
        int count = 0;

        while(current != NULL && (current->next != NULL)) {
            if(count == index) {
                return current;
            }
            count++;
            current = current->next;
        }
    }

    T GetItem(int index) {

        Node * node = GetNode(index);

        if(node != NULL) {
            return node->value;
        }
    }


    bool UpdateItem(int index, T value) {

        Node * node = GetNode(index);

        if(node != NULL) {
            node->value = value;
            return true;
        }

        return false;
    }

    bool InsertAfter(int index,T value) {

        Node * node = GetNode(index);

        if(node != NULL) {
            InsertAfter(node, value);
            return true;
        }
        
        return false;
    }
    
};