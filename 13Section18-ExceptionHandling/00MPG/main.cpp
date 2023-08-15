// Section 18
// Miles Per Gallon - No Exception Handling
#include<iostream>

int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    if(gallons != 0){
        miles_per_gallon = static_cast<double>(miles) / gallons;
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }        
    else
        std::cerr << "Sorry, cant divide by zero" << std::endl;

    std::cout << "Bye" << std::endl;

    return 0;
}









  