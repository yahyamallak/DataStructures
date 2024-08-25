#include <iostream>

using namespace std;

int length(char * array) {

    int i = 0;

    while(array[i] != '\0') {
        i++;
    }
    
    return i;
}

void reverseString(char * sentence) {

    int i = 0;
    int j = length(sentence) - 1;

    while(i < j) {
        char temp = sentence[i];
        sentence[i] = sentence[j];
        sentence[j] = temp;

        i++;
        j--;
    }

    printf("%s", sentence);
}


int main() {

    char name[] = "Yahya mallak";

    reverseString(name);


    return 0;
}