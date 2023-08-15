#include<iostream>
#include<string>

using namespace std;

float calc_cost(float base_cost = 90.0, float tax_rate = 0.06, float shipping = 3.50);

void greeting(string name, string prefix = "Mr.", string suffix = "");

int main()
{
    float cost{};

    cost = calc_cost(100.0, 0.08, 4.25);        //will use no defaults
    cout << "Total cost: " << cost << endl;

    cost = calc_cost(100.0, 0.08);              //will use default shipping
    cout << "Total cost: " << cost << endl;

    cost = calc_cost(100.0);                    //will use default tax and shipping
    cout << "Total cost: " << cost << endl;
    
    cost = calc_cost();                         //will use all defaults: base_cost, tax and shipping
    cout << "Total cost: " << cost << endl;

    greeting("Baris Can");
    greeting("Baris Can", "Dr.", "M.D.");
    greeting("Johanas", "Professor", "Ph.D.");
    greeting("Merve Yilmaz", "Mrs.");

    return 0;
    
}

float calc_cost(float base_cost, float tax_rate, float shipping)
{
    return base_cost += (base_cost * tax_rate) + shipping;
}

void greeting(string name, string prefix, string suffix)
{
    cout << "Hello " << prefix + " " + name + " " + suffix << endl;
}






