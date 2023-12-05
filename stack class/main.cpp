#include <iostream>
#include "clsMyStack.h"


using namespace std;


int main() {

    clsMyStack <int> MyStack;

    MyStack.push(10);
    MyStack.push(5);
    MyStack.push(2);
    MyStack.push(6);
    MyStack.push(1);

    MyStack.Print();

    cout << "Size : " << MyStack.Size() << endl;
    cout << "Top : " << MyStack.Top() << endl;
    cout << "Bottom : " << MyStack.Bottom() << endl;

    MyStack.pop();

    MyStack.UpdateItem(1, 4);

    MyStack.Print();

    cout << MyStack.GetItem(2) << endl;

    MyStack.Reverse();

    MyStack.Print();

    MyStack.UpdateItem(1, 4);

    MyStack.Print();

    MyStack.InsertAfter(1, 9);

    MyStack.Print();

    MyStack.InsertAtFront(3);

    MyStack.Print();

    MyStack.InsertAtBack(7);

    MyStack.Print();


    return 0;
}