#include<iostream>

using namespace std;

int *create_array(size_t size, int init_value = 0);

int main()
{
    cout << "What size do you need? ";
    size_t size{};
    cin >> size;

    int value{7};

    cout << "Array creating.." << endl;
    int *array_ptr{create_array(size, value)};
    cout << "\nArray created. Elements are: " << endl;

    for (size_t i = 0; i < size; i++)
    {
        cout << array_ptr[i] << endl;
    }
    delete []array_ptr;

    return 0;
}

int *create_array(size_t size, int init_value)
{
    int *array_in_func{};

    array_in_func = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        *(array_in_func + i) = init_value;
    }
    
    return array_in_func;
}







