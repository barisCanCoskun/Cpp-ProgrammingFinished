// Section 18
// Miles Per Gallon - User-defined Exception Classes
#include<iostream>

class DivideByZeroException
{
public:
    DivideByZeroException() = default;
    ~DivideByZeroException() = default;
};

class NegativeValueException
{
public:
    NegativeValueException() = default;
    ~NegativeValueException() = default;
};

double calculate_mpg(int miles, int gallons){
    if(gallons == 0)
		throw DivideByZeroException();
	if(miles < 0 || gallons < 0)
		throw NegativeValueException();

    return static_cast<double>(miles) / gallons;
}

int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    try{
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }        
    
    catch(const DivideByZeroException &ex){
        std::cerr << "Sorry, cant divide by zero" << std::endl;
    }

    catch(const NegativeValueException &ex){
        std::cerr << "Negative values aren't allowed" << std::endl;
    }
    
    // also possible to have a catch-all handler
    // this catch handler will fire no matter what type of exception is thrown 
    catch(...){
        std::cerr << "Unknown exception" << std::endl;
    }
    
    std::cout << "Bye" << std::endl;

    return 0;
}









  


  