// Section 19
// Stream manipulators - Boolean
// boolalpha and noboolalpha

#include<iostream>
#include<iomanip>       // must include for manipulators

int main()
{
    std::cout << "noboolalpha -default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha -default (10 == 20): " << (10 == 20) << std::endl;

    // Set to true/false formatting
    std::cout << std::boolalpha;        // change to true/false
    std::cout << "noboolalpha -default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha -default (10 == 20): " << (10 == 20) << std::endl;

    // Setting still stays for future boolean insertions
    std::cout << "noboolalpha -default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha -default (10 == 20): " << (10 == 20) << std::endl;

    // Toggle to 0/1
    std::cout << std::noboolalpha;        // change to true/false
    std::cout << "noboolalpha -default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha -default (10 == 20): " << (10 == 20) << std::endl;

    // Set back to true/false using setf method
    std::cout.setf(std::ios::boolalpha);
    std::cout << "noboolalpha -default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha -default (10 == 20): " << (10 == 20) << std::endl;

    // resets to default which is 0/1 
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "noboolalpha -default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha -default (10 == 20): " << (10 == 20) << std::endl;

    return 0;
}









