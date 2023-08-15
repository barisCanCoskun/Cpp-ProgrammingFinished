// Section 19
// Copy File 2
// File copying using get/put
#include<iostream>
#include<fstream>
#include<iomanip>

int main()
{
    std::ifstream in_file{"poem.txt"};
    std::ofstream out_file{"poem_out.txt"};;
    char c{};

    if(!in_file){
        std::cerr << "Problem opening input file" << std::endl;
        return 1;
    }

    if(!out_file){
        std::cerr << "Problem opening output file" << std::endl;
        return 1;
    }

    while (in_file.get(c))
        out_file.put(c);

    std::cout << "File copied" << std::endl;
    in_file.close();
    out_file.close();
    return 0;
}









