#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<string>
#include<iomanip>

template<typename T1, typename T2>
void display(const std::map<T1, T2> &map)
{
    std::cout << "\n";
    std::cout << std::setw(15) << std::left << "Word" << ": " 
              << std::setw(5) << std::left << "# Times" << "\n";
    std::cout << "\n";
    for (const auto &m: map)
        std::cout << std::setw(15) << std::left << m.first << ": " 
                  << std::setw(5) << std::left << m.second << "\n";
}

void display(const std::map<std::string, std::set<int>> &map)
{
    std::cout << "\n";
    std::cout << std::setw(15) << std::left << "Word" << ": " 
              << std::setw(5) << std::left << "Line Numbers" << "\n";
    std::cout << "\n";
    for (const auto &m: map){
        std::cout << std::setw(15) << std::left << m.first << ": ";
        std::cout << "[ ";
        for(const auto &l: m.second)
            std::cout << l << " ";
        std::cout << "]" << std::endl;
    }
}

// This func removes periods, commas, semicolons, colon
// in a string and returns the clean version
std::string clean_string(const std::string &s)
{
    std::string result;

    for(const &c: s){
        if((c == '.') || (c == ',') || (c == ':') || (c == ';'))
            continue;
        else
            result += c;
    }
    return result;
}

void part1()
{    
    std::cout << "Part1" << std::setfill('=') << std::setw(20) << "" << std::endl;
    std::cout << std::setfill(' ');

    std::ifstream in_file;
    std::string word;
    std::map<std::string, int> words;

    in_file.open("words.txt");
    if(in_file){        
        while (in_file >> word){
            word = clean_string(word);
            ++words[word];
        }       
        in_file.close();
        display(words);
    }
    else
        std::cerr << "Problem opening file" << std::endl;
}

void part2()
{    
    std::cout << "\nPart2" << std::setfill('=') << std::setw(20) << "" << std::endl;
    std::cout << std::setfill(' ');

    std::ifstream in_file;
    std::string line;
    std::string word;
    std::map<std::string, std::set<int>> words;
    size_t line_number{};

    in_file.open("words.txt");
    if(in_file){        
        while (std::getline(in_file, line))
        {
            ++line_number;
            std::istringstream iss{line};
            while (iss >> word)
            {
                word = clean_string(word);
                words[word].emplace(line_number);
            }
        }        
        in_file.close();
        display(words);
    }
    else
        std::cerr << "Problem opening file" << std::endl;
}

int main()
{
    part1();
    part2();

    return 0;
}









