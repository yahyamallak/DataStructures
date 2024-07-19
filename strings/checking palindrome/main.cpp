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

bool checkPalindrome(char * sentence) {

    int len = length(sentence);

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if(lowercase(sentence[i]) != lowercase(sentence[j])) {
            return false;
        }
    }

    return true;
    
}


int main() {


    char sentence[] = "Yahay";

    if(checkPalindrome(sentence)) {
        cout << "Palindrome";
    } else {
        cout << "Not a palindrome";
    }


    return 0;
}