// Section 19
// Copy File 1
// File copying using getline
#include<iostream>
#include<fstream>

int main()
{
    std::ifstream in_file{"poem.txt"};
    std::ofstream out_file{"poem_out.txt"};;
    std::string line{};

    if(!in_file){
        std::cerr << "Problem opening input file" << std::endl;
        return 1;
    }

    if(!out_file){
        std::cerr << "Problem opening output file" << std::endl;
        return 1;
    }

    while (std::getline(in_file, line))     // we used formatted input and output 
        out_file << line << std::endl;    

    std::cout << "File copied" << std::endl;

    in_file.close();
    out_file.close();
    return 0;
}









