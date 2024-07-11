#include <iostream>

using namespace std;


int length(char * array) {

    int i = 0;

    while(array[i] != '\0') {
        i++;
    }
    
    return i;
}


int main() {


    char name[] = {'Y', 'A','H','Y','A', '\0'};


    printf("%s", name);

    cout << endl << length(name);

    return 0;
}