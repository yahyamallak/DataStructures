#include <iostream>


using namespace std;


template<class T>

class Array {




public:
    int * _A;
    int _length;
    int _size;

    Array() {
        _A = new T[10];
        _length = 0;
        _size = 10;
    }

    Array(int size) {
        _A = new T[size];
        _length = 0;
        _size = size;
    }

    ~Array() {
        
    }

    bool Append(T value) {
        if(_size == _length) {
            cout << "Sorry, Array is full" << endl;
            return false;
        }

        _A[_length] = value;
        _length++;

        return true;
    }

    T Get(int index) {
        if(index < _length && index >= 0)
            return _A[index];
    }

    bool Set(int index, T value) {
        if(index < _length && index >= 0)
            _A[index] = value;
            return true;
        
        return false;
    }

    T Max() {

        int max = _A[0];

        for (int i = 1; i < _length; i++)
        {
            if(_A[i] > max) {
                max = _A[i];
            }
        }
        
        return max;
    }

    T Min() {

        int min = _A[0];

        for (int i = 1; i < _length; i++)
        {
            if(_A[i] < min) {
                min = _A[i];
            }
        }
        
        return min;
    }

    bool Insert(int index, T value) {

        if(_size == _length || index > _length) {
            return false;
        }

        if(_length == 0) {
            _A[0] = value;
            _length++;
            return true;
        }

        for (int i = _length; i > index; i--)
        {
            _A[i] = _A[i - 1];
        }

        _A[index] = value;
        _length++;
        return true;


    }

    bool Delete(int index) {

        if(_length == 0 || index >= _length) {
            return false;
        }

        for(int i = index; i < _length - 1; i++) {
            _A[i] = _A[i + 1];
        }

        _length--;
        return true;
    }

    bool Find(T value) {
        for (int i = 0; i < _length; i++)
        {
            if(_A[i] == value) {
                T temp = _A[i - 1];
                _A[i - 1] = _A[i];
                _A[i] = temp;
                return true;
            }
        }

        return false;
        
    }

    void Sort() {
        for (int i = 0; i < _length; i++)
        {
            for (int j = 0; j < _length - 1; j++)
            {
                if(_A[j] > _A[j + 1]) {
                    int temp = _A[j];
                    _A[j] = _A[j + 1];
                    _A[j + 1] = temp;
                }
            }
        }
        
    }

    int FindUsingBinarySearch(T value) {

        int start = 0;
        int end = _length - 1;

        for (int i = start; i < end; i++)
        {
            int mid = (start + end) / 2;

            if(_A[mid] == value) {
                return mid;
            } else if(_A[mid] < value) {
                start = mid + 1;
            } else if(_A[mid] > value) {
                end = mid - 1;
            }
        }

        return -1;
        
    }

    int RecursiveBinarySearch(T value, int start, int end) {

        if(start <= end) {

            int mid = (start + end) / 2;

            if(_A[mid] == value) {
                return mid;
            } else if(_A[mid] < value) {
                return RecursiveBinarySearch(value, mid + 1, end);
            } else if(_A[mid] > value) {
                return RecursiveBinarySearch(value, start, mid - 1);
            }
        }

        return -1;
    }
    
    void Display() {
        for (int i = 0; i < _length; i++)
        {
            cout << _A[i] << " ";
        }
        
    }

    void Reverse() {

        for(int i = 0, j = _length - 1; i < j; i++, j--) {
            T temp = _A[i];
            _A[i] = _A[j];
            _A[j] = temp;
        }

    }

    void LeftShift() {

        T temp = _A[0];

        for (int i = 0; i < _length - 1; i++)
        {
            _A[i] = _A[i + 1];
        }
        
        _A[_length - 1] = temp;
    }

    void RightShift() {

        T temp = _A[_length - 1];

        for (int i = _length - 1; i > 0; i--)
        {
            _A[i] = _A[i - 1]; 
        }
        
        _A[0] = temp;
    }

    bool isSorted() {
        for (int i = 0; i < _length - 1; i++)
        {
            if(_A[i] > _A[i + 1]) {
                return false;
            }
        }
        
        return true;
    }

    bool InsertSorted(T value) {

        if(_length == _size) {
            return false;
        }

        for (int i = _length - 1; i > 0 ; i--)
        {
            if(_A[i] > value) {
                _A[i + 1] = _A[i];
            } else {
                _A[i + 1] = value;
                _length++;
                return true;
            }

        }

    }

    void FindMissingElementSorted() {
        
        int diff = _A[0];

        for (int i = 0; i < _length; i++)
        {
            if((_A[i] - i) != diff) {

                while(diff < (_A[i] - i)) {
                    cout << diff + i << " ";
                    diff++;
                }

            }
        }
        
    }

    void FindMissingElement() {

        int big = _A[0];
        int small = _A[0];

        for (int i = 1; i < _length; i++)
        {
            if(_A[i] > big) {
                big = _A[i];
            }else if(_A[i] < small) {
                small = _A[i];
            }
        }
        
        int hashTable[big] = {0};


        for (int i = 0; i < _length; i++)
        {
            hashTable[_A[i]] = 1;
        }


        for (int i = small; i < big; i++)
        {
            if(hashTable[i] == 0) {
                cout << i << " ";
            }
        }
        
        

    }


    void findDuplicatesSorted() {

        T lastDuplicate;
        int j = 0;

        for (int i = 0; i < _length - 1; i++)
        {
            if(_A[i] == _A[i + 1] && _A[i] != lastDuplicate) {

                j = i + 1;

                while(_A[i] == _A[j]) {
                    j++;
                }

                int times = j - i;

                lastDuplicate = _A[i];

                cout << "Duplicate : " << _A[i] <<", " << times << " times." << endl;
            
                i = j - 1;
            }
        }
        
    }

    void findDuplicates() {
        int big = _A[0];
        int small = _A[0];
        int length;

        for (int i = 1; i < _length; i++)
        {
            if(_A[i] > big) {
                big = _A[i];
            } else if(_A[i] < small) {
                small = _A[i];
            }
        }

        length = big + 1;
        
        int hashTable[length] = {0};


        for (int i = 0; i < _length; i++)
        {
            hashTable[_A[i]] += 1;
        }

        for (int i = 0; i < length; i++)
        {
            if( hashTable[i] > 1 ) {
                cout << "Duplicates : " << i << ", " << hashTable[i] << " times." << endl;
            }
        }
        
    }


    void findThePairOfElementsGivenASum(int sum) {

        int big = _A[0];
        int small = _A[0];
        int length;

        for (int i = 1; i < _length; i++)
        {
            if(_A[i] > big) {
                big = _A[i];
            } else if(_A[i] < small) {
                small = _A[i];
            }
        }

        length = big + 1;
        
        int hashTable[length] = {0};


        for (int i = 0; i < _length; i++)
        {
            int missing = sum - _A[i];
            
            if(missing > 0 && missing < length) {

                if(hashTable[missing] != 0) {
                    cout << _A[i] << " + " << missing << " = " << sum << endl;
                } 

                hashTable[_A[i]]++;
            }

        }
        

    }

    void findThePairOfElementsGivenASumSorted(int sum) {

        int i = 0;
        int j = _length - 1;

        while(i < j) {

            if(_A[i] + _A[j] == sum) {
                cout << _A[i] << " + " << _A[j] << " = " << sum << endl;
                i++;
                j--;
            } else if(_A[i] + _A[j] > sum) {
                j--;
            } else if(_A[i] + _A[j] < sum) {
                i++;
            }

        }
    }

};





int main() {

    Array<int> array(20);

    array.Append(5);
    array.Append(2);
    array.Append(2);
    array.Append(2);
    array.Append(1);
    array.Append(8);
    array.Append(8);
    array.Append(10);

    array.Sort();
    array.Display();

    cout << endl;

    array.findThePairOfElementsGivenASumSorted(10);

    return 0;

}