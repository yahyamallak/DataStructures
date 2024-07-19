#include <iostream>


using namespace std;

int length(char * array) {

    int i = 0;

    while(array[i] != '\0') {
        i++;
    }
    
    return i;
}

void findDuplicates(char * sentence) {

    int len = length(sentence);
    int range = 52;

    int hashtable[range] = {0};

    for (int i = 0; i < len; i++)
    {
        if(sentence[i] <= 90 && sentence[i] >= 65) {
            hashtable[sentence[i] - 65] += 1;
        }else if(sentence[i] <= 122 && sentence[i] >= 97) {
            hashtable[sentence[i] - 71] += 1;
        }
    }
    
    
    for (int i = 0; i < range; i++)
    {
        if(hashtable[i] > 1) {
            if(i <= 25 && i >= 0) {
                cout <<  char(i + 65) << " Duplicated " << hashtable[i] << " times." << endl;
            }else if(i <= 51  && i >= 26) {
                cout <<  char(i + 71) << " Duplicated "  << hashtable[i] << " times." << endl;
            }
        }
    }
    
}


int main() {

    char sentence[] = "Yahya mallak";


    findDuplicates(sentence);

    return 0;
}