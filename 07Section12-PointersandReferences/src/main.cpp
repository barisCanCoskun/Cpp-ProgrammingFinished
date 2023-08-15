#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{   
    //in these examples, we're initializing the pointer variables to zero
    //that's what null pointer represents 
    //this means that we're initializing the pointers to point nowhere.
    //that's very different from pointing anywhere.
    int *int_ptr{};
    cout << int_ptr << endl;

    double *double_ptr{nullptr};        // pointing nowhere
    cout << double_ptr << endl;

    char *char_ptr{nullptr};
    // cout << *char_ptr << endl;          // displays nothing and finishes program

    string *string_ptr{nullptr};

    int x{7};
    int *int_ptr1{&x};
    cout << int_ptr1 << endl;
    cout << *int_ptr1 << endl;
    cout << sizeof x << endl;
    cout << "size of pointer int_ptr1: " << sizeof int_ptr1 << endl;

    int *ptr;
    cout << "size of pointer ptr: " << sizeof ptr << endl;
    cout << "value of pointer ptr: " << ptr << endl;
    cout << "address of pointer ptr: " << &ptr << endl;

    vector<string> stooges{"Lary", "Mary", "Harry"};
    vector<string> *vector_ptr{&stooges};

    cout << "First element of stooges: " << (*vector_ptr).at(0) << endl;

    for (auto s: *vector_ptr)
        cout << s << endl;

    int *int_ptr2{nullptr};
    cout << "Before value of pointer int_ptr2: " << int_ptr2 << endl;

    // Rather than assinging address of some integer variable, 
    // we create an integer runtime and store variables address in int_ptr2
    int_ptr2 = new int;          // allocate an integer on the heap
    cout << "After value of pointer int_ptr2: " << int_ptr2 << endl;

    cout << "\nvalue of dereference pointer int_ptr2: " << *int_ptr2 << endl;         // garbage

    delete int_ptr2;         // frees allocated memory: allocated storage is now free to be used again   
    int_ptr2 = nullptr;      // best practice after calling delete 

    *int_ptr2 = 7;
    cout << "\nAfter deleting, value of pointer int_ptr2: " << int_ptr2 << endl;

    cout << "After deleting, value of dereference pointer int_ptr2: " << *int_ptr2 << endl;         // garbage

    // When you allocate storage in this manner, the storage is on the heap, the allocated storage contains garbage data until you initialize it. 
    // The allocated storage does not have a name. The only way to get to that storage is via the pointer. 
    // If you lose the pointer because it goes out of scope or you reassign it, then you lost your only way to get to that storage
    // and YOU HAVE A MEMORY LEAK !!!
    
    // Finally, when you're done using the storage, then you must de-allocate it, so that it's again available 
    // to rest of the program.      delete int_ptr2; 

    return 0;    
}










