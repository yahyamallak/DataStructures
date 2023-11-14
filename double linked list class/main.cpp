#include <iostream>
#include "clsDblLinkedList.h"


using namespace std;


int main() {

    clsDblLinkedList <int> MydblLinkedList;

    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(7);
    MydblLinkedList.InsertAtBeginning(1);
    MydblLinkedList.InsertAtBeginning(6);
    MydblLinkedList.InsertAtBeginning(5);

    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAfter(2, 5);

    MydblLinkedList.PrintList();

    return 0;
}