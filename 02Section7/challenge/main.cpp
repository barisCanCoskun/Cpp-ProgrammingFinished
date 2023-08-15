#include<iostream>
#include<vector>            //include vector LIBRARY

using namespace std;     //vector type is part of the standard library

int main()
{

    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "There are " << vector1.size() << " elements in vector1: " << vector1.at(0) << " , " << vector1.at(1) << endl;
    
    vector2.push_back(30);
    vector2.push_back(40);
    vector2.push_back(50);

    cout << "There are " << vector2.size() << " elements in vector2: " << vector2.at(0) << " , " << vector2.at(1) << " , " << vector2.at(2) << endl;

    vector <vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << "\n" << vector_2d.size() << " elements in vector_2d" << endl;
    cout << "Elements of vector1 in vector_2d: " << vector_2d.at(0).at(0) << " , " << vector_2d.at(0).at(1) << endl;
    cout << "Elements of vector2 in vector_2d: " << vector_2d.at(1).at(0) << " , " << vector_2d.at(1).at(1) << " , " << vector_2d.at(1).at(2) << endl;

    vector1.at(0) = 1000;

    cout << "\nAfter change of first element of vector1 to " << vector1.at(0) << endl;
    cout << "Elements of vector1 in vector_2d: " << vector_2d.at(0).at(0) << " , " << vector_2d.at(0).at(1) << endl;
    cout << "Elements of vector2 in vector_2d: " << vector_2d.at(1).at(0) << " , " << vector_2d.at(1).at(1) << " , " << vector_2d.at(1).at(2) << endl;

    cout << "\nElements of vector1: " << vector1.at(0) << " , " << vector1.at(1) << endl;

    return 0;
    
}









