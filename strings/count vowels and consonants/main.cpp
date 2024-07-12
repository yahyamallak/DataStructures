#include <iostream>

using namespace std;


void countVowelsAndConsonants(char * sentence) {

    int vowels = 0, consonants = 0;

    for (int i = 0; sentence[i] != '\0' ; i++ )
    {
        if(sentence[i] == 'a' || sentence[i] == 'A' || sentence[i] == 'e' || sentence[i] == 'E' || sentence[i] == 'i' || sentence[i] == 'I' || sentence[i] == 'o' || sentence[i] == 'O' || sentence[i] == 'u' || sentence[i] == 'U' || sentence[i] == 'y' || sentence[i] == 'Y') {
            vowels++;
        } else if((sentence[i]>=65 && sentence[i]<=90) || (sentence[i] >= 97 && sentence[i] <= 122)) {
            consonants++;
        }
        
        
    }

    cout << "Vowels = " << vowels << " , Consonants = " << consonants;
    
}


int main() {

    char name[] = {'Y', 'a', 'h', 'y', 'a', ' ', 'M', 'a','l','l','a','k', '\0'};


    countVowelsAndConsonants(name);

    return 0;
}