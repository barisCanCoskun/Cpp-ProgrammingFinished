// Section 19
// stringstreams
#include<iostream>
#include<sstream>
#include<iomanip>
#include<limits>

int main()
{
    int num{};
    double total{};
    std::string name{};

    std::string info{"Joe   77  56.75"};
    std::istringstream iss{info};
    iss >> name >> num >> total;
    std::cout << iss.str() << std::endl;

    std::cout << "---------------------------------" << std::endl;

    std::ostringstream oss{};
    oss << name << " " << num << " " << total;
    std::cout << oss.str() << std::endl;

    std::cout << "\n-----Data validation----------------------------" << std::endl;

    int value{};
    std::string input{};

    // std::cout << "Enter an integer: ";
    // std::cin >> input;

    // std::stringstream ss{input};
    // if(ss >> value)
    //     std::cout << "An integer was entered" << std::endl;
    // else
    //     std::cout << "An integer was NOT entered" << std::endl;

    bool done = false;
    do{
        std::cout << "Enter an integer: ";
        std::cin >> input;
        std::istringstream validator{input};
        if(validator >> value)
            done = true;
        else
            std::cout << "Thats not an integer" << std::endl;

        // discards the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(!done);
    
    std::cout << "You entered the integer: " << value << std::endl;
    return 0;
}









