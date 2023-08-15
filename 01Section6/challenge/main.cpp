#include<iostream>

using namespace std;

int main()
{
    int small_rooms{0};
    int large_rooms{0};

    cout << "Enter number of small rooms: " << endl;
    cin >> small_rooms;
    cout << "Enter number of large rooms: " << endl;
    cin >> large_rooms;

    const float charge_small_room{25.0};
    const float charge_large_room{35.0};
    const float tax_rate{0.06};
    const int expiration{30}; //days

    float cost{(small_rooms * charge_small_room) + (large_rooms * charge_large_room)};
    float tax{tax_rate * cost};
    float total_estimate{cost + tax};
    
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_rooms << endl;
    cout << "Number of large rooms: " << large_rooms << endl;
    cout << "Price per small room: " << charge_small_room << endl;
    cout << "Price per large room: " << charge_large_room << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Tax: $" << tax << endl;

    cout << "\nTotal estimate: $" << total_estimate << endl;
    cout << "This estimate is valid for " << expiration << " days" << endl;
    

    return 0;
    
}