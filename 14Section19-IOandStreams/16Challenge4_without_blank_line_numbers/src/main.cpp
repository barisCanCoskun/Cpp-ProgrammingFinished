// Section 19
// Challenge 4
// File copying with line numbers
#include<iostream>
#include<fstream>

int main()
{
    std::ifstream in_file{"romeoandjuliet.txt"};
    std::ofstream out_file{"romeoandjuliet_out.txt"};;
    std::string line{};
    size_t line_number{};

    if(!in_file){
        std::cerr << "Problem opening input file" << std::endl;
        return 1;
    }

    if(!out_file){
        std::cerr << "Problem opening output file" << std::endl;
        return 1;
    }

    while (std::getline(in_file, line)){
        if(line != "")
            out_file << ++line_number << "\t";
        out_file << line << std::endl; 
    }   

    std::cout << "File copied" << std::endl;

    in_file.close();
    out_file.close();
    return 0;
}









