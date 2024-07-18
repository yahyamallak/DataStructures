#include <iostream>

using namespace std;


int length(char * array) {

    int i = 0;

    while(array[i] != '\0') {
        i++;
    }
    
    return i;
}

char lowercase(char character) {

    if(character < 97 || character > 122) {
        return character + 32;
    }

    return character;
}

bool compare(char * sentence1, char * sentence2) {

    int len;
    
    if(length(sentence1) <= length(sentence2)) {
        len = length(sentence1);
    } else {
        len = length(sentence2);
    }


    for (int i = 0; i < len; i++)
    {
        if(lowercase(sentence1[i]) != lowercase(sentence2[i])) {
            return false;
        }
    }

    return true;
    
}


int main() {



    char sentence1[] = "Yahya mallak";
    char sentence2[] = "yahya mallak";


    if(compare(sentence1, sentence2)) {
        cout << "Same";
    } else {
        cout << "Different";
    }



    return 0;
}