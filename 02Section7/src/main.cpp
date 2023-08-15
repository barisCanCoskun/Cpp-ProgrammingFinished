#include<iostream>

using namespace std;

int main()
{
    // cout << "sde" << endl;

    //initialization list
    int test_scores[5] {100, 95, 80, 50, 70};

    cout << test_scores[6] << endl;

    int high_score_per_level[10] {3, 5};        // init to 3, 5 and remaining to 0

    const int days_in_year{365};
    float hi_temperatures[days_in_year] {0};    // init all to zero

    int another_array[] {1,2,3,4,5};            // size automatically calculated 

    test_scores[3] = 85;                        // assignment statement
    cout << "\nChanged test score is: " << test_scores[3] << endl;

    char vowels[] {'a', 'e', 'i', 'o', 'u'};
    cout << "\nThe first vowel is: " << vowels[0] << endl;

    const int rows {3};
    const int cols {4};

    int movie_rating [rows][cols] {
        {0, 4, 3, 5},
        {2, 3, 5, 1},
        {3, 3, 2, 1}
    };

    movie_rating[1][3] = 3;

    cout << "rating of movie of 2. person 4th movie: " << movie_rating[1][3] << endl;


    return 0;
    
}