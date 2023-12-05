#include <iostream>
#include "clsMyQueue.h"

using namespace std;


template <class T> class clsMyStack : public clsMyQueue <T> {

    public:

    void push(T value) {
        clsMyQueue <T>::InsertAtFront(value);
    }

    T Top() {
        return clsMyQueue <T>::Front();
    }

    T Bottom() {
        return clsMyQueue <T>::Back();
    }
};