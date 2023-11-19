#include <iostream>
#include "clsMyQueue.h"


using namespace std;


int main() {

    clsMyQueue <int> MyQueue;

    MyQueue.push(7);
    MyQueue.push(2);
    MyQueue.push(1);
    MyQueue.push(4);
    MyQueue.push(3);
    MyQueue.push(8);

    MyQueue.Print();

    cout << "Size : " << MyQueue.Size() << endl;
    cout << "Front : " << MyQueue.Front() << endl;
    cout << "Back : " << MyQueue.Back() << endl;

    MyQueue.pop();

    MyQueue.Print();

    MyQueue.Reverse();

    MyQueue.UpdateItem(1, 6);

    MyQueue.Print();

    MyQueue.InsertAfter(2, 10);

    MyQueue.Print();

    MyQueue.InsertAtFront(5);

    MyQueue.Print();

    MyQueue.InsertAtBack(8);

    MyQueue.Print();

    cout << "After Clear : ";

    MyQueue.Clear();

    MyQueue.Print();

    return 0;
}