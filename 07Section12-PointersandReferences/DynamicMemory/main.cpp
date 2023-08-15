#include<iostream>

using namespace std;

int main()
{
    int *array_ptr{nullptr};
    size_t size{};

    cout << "How many elements do you wish in your array ?" << endl;
    cin >> size;

    array_ptr = new int [size];          // allocate array on the heap

    delete [] array_ptr;
    array_ptr = nullptr;                // if i lose array_ptr pointer like this statement before deleting it, 
                                        // i would just lost my only way to get to allocated storage.
                                        // that would be memory leak!!

// we allocate an entire array of ints on the HEAP at runtime.

    return 0;
    
}









