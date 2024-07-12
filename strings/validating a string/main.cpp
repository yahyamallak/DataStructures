// string should not contain special characters
#include <iostream>
#include <regex>

using namespace std;


bool doesStringContainSpecialChars(char * sentence) {

    regex expr("[^a-zA-Z0-9 ]");

    if(regex_search(sentence, expr)) {
        return true;
    }

    return false;
}


int main() {


    char name[] = "Yahya mallak";

    if(doesStringContainSpecialChars(name)) {
        cout << "The sentence contains special chars." << endl;
    } else {
        cout << "The sentence doesn't contain special chars." << endl;
    }


    return 0;
}