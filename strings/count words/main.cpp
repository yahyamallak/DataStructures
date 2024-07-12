#include <iostream>

using namespace std;

void countWords(char * sentence) {

    int words = 0;

    for (int i = 0; sentence[i] != '\0'; i++)
    {

        if(i == 0 && sentence[i] != ' ') {
            words++;
        }

        if(sentence[i] == ' ' && sentence[i + 1] != ' ') {
            words++;
        }
    }
    
    cout << "Count of words : " << words;

}


int main() {

    char name[] = "  Yahya   mallak 2024";


    printf("%s", name);

    cout << endl;

    countWords(name);

    return 0;
}