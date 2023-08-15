// Section 19
// Read File 1
// Test file open and simple read of 3 data items 
#include<iostream>
#include<fstream>

int main()
{
    std::ifstream in_file;
    std::string line;
    int num;
    double total;

    in_file.open("test.txt");
    if(!in_file){
        std::cerr << "Problem opening file" << std::endl;
        return 1;
        // std::exit(1);        // bu da olabilirdi 
    }

    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << total << std::endl;
    std::cout << num << std::endl;
    in_file.close();

    // std::cout << "File is good to go" << std::endl;

    return 0;
}









