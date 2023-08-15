// Section 19
// Stream manipulators - Boolean
// boolalpha and noboolalpha

#include<iostream>
#include<iomanip>       // must include for manipulators

int main()
{
    int num{255};

    // Display using different bases
    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // Display showing the base prefix for hex and oct
    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // Display the hex value in uppercase
    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    // Display the + sign in front of positive base 10 numbers
    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // Setting using the set method	
	std::cout.setf(std::ios::showbase);
	std::cout.setf(std::ios::uppercase);
	std::cout.setf(std::ios::showpos);

    // resetting to defaults
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);



    std::cout << std::endl;
    return 0;
}









