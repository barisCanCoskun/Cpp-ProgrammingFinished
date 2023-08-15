#include<iostream>

using namespace std;

 int *apply_all(int [], size_t, int [], size_t);
 void print(const int [], size_t);

int main()
{
    int array1[4]{1, 2, 3, 4};
    int array2[3]{10, 20, 30};

    int *array_main = apply_all(array1, 4, array2, 3);
    
    print(array_main, 12);

    delete []array_main;
    array_main = nullptr;

    return 0;
}

int *apply_all(int array1[], size_t size1, int array2[], size_t size2)
{
    size_t k{};
    int *new_array{nullptr};

    new_array = new int [size1 * size2];

    for (size_t i = 0; i < size2; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            new_array[k++] = array1[j] * array2[i];
        }
    }
    
    return new_array;
}

void print(const int a[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}









