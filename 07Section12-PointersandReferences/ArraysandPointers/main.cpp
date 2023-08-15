#include<iostream>

using namespace std;

int main()
{
    int scores[]{100, 90, 75};

    cout << scores << endl;
    cout << *scores << endl;

    int *score_ptr{scores};

    cout << "score_ptr[0]: " << score_ptr[0] << endl;
    cout << "*score_ptr: "   << *score_ptr << endl;
    cout << "*(score_ptr + 1): " << *(score_ptr + 1) << endl;

    cout << "*(scores + 2): " << *(scores + 2) << endl;


    return 0;
}









