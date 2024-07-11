#include <iostream>


using namespace std;


int * Append(int * array, int size, int * array2, int size2) {

    int * array3 = new int[size + size2];

    for (int i = 0; i < size; i++)
    {
        array3[i] = array[i];
    }

    for (int j = 0; j < size2; j++)
    {
        array3[j + size] = array2[j];
    }

    return array3;
    
}

int * Merge(int * array, int size, int * array2, int size2) {
    
    int * array3 = new int[size + size2];

    int i = 0, j = 0, k = 0;

    while(i < size && j < size2) {

        if(array[i] < array2[j]) {
            array3[k++] = array[i++];
        } else {
            array3[k++] = array2[j++];
        }
    }

    for(;i<size;i++) {
        array3[k++] = array[i];
    }

    for(;j<size2;j++) {
        array3[k++] = array2[j];
    }
    

    return array3;
}




void PrintArray(int * array, int size) {

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    
}


int main() {


    int nums[4] = {1, 3, 5, 6};
    int nums2[4] = {0, 2, 7, 10};
    

    int * nums3 = Merge(nums, 4, nums2, 4);

    PrintArray(nums3, 8);

    return 0;
}