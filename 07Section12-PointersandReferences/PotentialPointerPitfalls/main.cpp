#include<iostream>

using namespace std;

int main()
{
    int x{7};
    
    int *int_ptr1{&x};
    int *int_ptr2{&x};

    cout << "Address of x in int_ptr1: " << int_ptr1 << endl;
    cout << "Value of x in int_ptr1: " << *int_ptr1 << endl;

    delete int_ptr1;
    int_ptr1 = nullptr;

    cout << "\nAfter deleting int_ptr1, int_ptr2 accessing to released data...\n " << endl;
    // cout << "Value of x in int_ptr1: " << *int_ptr1 << endl;

    cout << "Address of x in int_ptr2: " << int_ptr2 << endl;
    
    //Dangling Pointer: pointer accesses to released data 
    cout << "Value of x in int_ptr2: " << *int_ptr2 << endl;
    

    return 0;
    
}











