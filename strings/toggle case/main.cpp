#include <iostream>

using namespace std;


int length(char * characters) {

    int i = 0;

    while(characters[i] != '\0') {
        i++;
    }
    
    return i;
}

void togglecase(char * characters) {

    for (int i = 0; i < length(characters); i++)
    {
        if(characters[i] < 65 || characters[i] > 90) {
            characters[i] = characters[i] - 32;
        } else if(characters[i] < 97 || characters[i] > 122) {
            characters[i] = characters[i] + 32;

        }
    }

    for (int i = 0; i < length(characters); i++)
    {
        cout << characters[i];
    }
    
}


int main() {


    char name[] = {'y', 'a','H','y','A', '\0'};
    
    printf("%s", name);

    cout << endl;

    togglecase(name);


    return 0;
}