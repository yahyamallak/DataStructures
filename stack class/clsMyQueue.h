#include <iostream>
#include "clsDblLinkedList.h"


using namespace std;



template <class T> class clsMyQueue {

    protected:

    clsDblLinkedList <T> MyQueue;

    public:

    void push(T value) {
        MyQueue.InsertAtEnd(value);
    }


    void Print() {
        MyQueue.PrintList();
    }


    void pop() {
        MyQueue.DeleteFirstNode();
    }

    int Size() {
        return MyQueue.Size();
    }

    T Front() {
        return MyQueue.GetItem(0);
    }

    T Back() {
        return MyQueue.GetItem(Size() - 1);
    }

    T GetItem(int index) {
        return MyQueue.GetItem(index);
    }

    void Reverse() {
        return MyQueue.Reverse();
    }

    bool UpdateItem(int index, T value) {
        return MyQueue.UpdateItem(index, value);
    }

    bool InsertAfter(int index, T value) {
        return MyQueue.InsertAfter(index, value);
    }

    void InsertAtFront(T value) {
         MyQueue.InsertAtBeginning(value);
    }

    void InsertAtBack(T value) {
        MyQueue.InsertAtEnd(value); 
    }

    void Clear() {
        MyQueue.Clear();
    }

};