#include <iostream>

using namespace std;


int length(char * characters) {

    int i = 0;

    while(characters[i] != '\0') {
        i++;
    }
    
    return i;
}

void lowercase(char * characters) {

    for (int i = 0; i < length(characters); i++)
    {
        if(characters[i] < 97 || characters[i] > 122) {
            characters[i] = characters[i] + 32;
        }
    }

    for (int i = 0; i < length(characters); i++)
    {
        cout << characters[i];
    }
    
}


int main() {


    char name[] = {'Y', 'a','H','Y','A', '\0'};
    
    printf("%s", name);

    cout << endl;

    lowercase(name);


    return 0;
}