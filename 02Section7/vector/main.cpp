#include<iostream>
#include<vector>            //include vector LIBRARY

using namespace std;     //vector type is part of the standard library

int main()
{
    // cout << "sde" << endl;

    // std::vector <char> vowels {'a', 'e', 'i', 'o', 'u'};     //vector type is part of the standard library

    vector <char> vowels (5);            //constructor initialization syntax

    vector <int> test_scores (10);      //unlike arrays, these 10 integers will be automatically set to 0

    vector <int> scores {100, 95, 80, 50, 30};

    cout << scores[2] << endl;          // array syntax

    cout << scores.at(3) << endl;       // vector syntax

    scores.push_back(70);                   // 100, 95, 80, 50, 30, 70

    scores.push_back(45);                   // 100, 95, 80, 50, 30, 70, 45

    for (size_t i = 0; i < scores.size(); i++)
    {
        // cout << scores[i] << endl;          // array syntax
        cout << scores.at(i) << endl;       // vector syntax
    }

    cout << "there are " << scores.size() << " scores in vector" << endl;

    // cout << scores.at(9) << endl;

    // cin >> scores.at(9);

    vector <vector<int>> movie_ratings{
        {1, 2, 3, 4},
        {1, 5, 2, 8},
        {0, 9, 1, 7}
    };
    
    cout << "second person forth movie: " << movie_ratings[1][3] << " rates" << endl;                // array syntax
    cout << "third person second movie: " << movie_ratings.at(2).at(1) << " rates" << endl;          // vector syntax

    return 0;
    
}









