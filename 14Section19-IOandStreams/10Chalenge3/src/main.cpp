// Section 19
// Challenge 3 - Word Finder
#include<iostream>
#include<fstream>
#include<iomanip>

int main()
{
    std::ifstream in_file;
    std::string word;    
    std::string searched_word; 
    int counter_searched_word{};
    int counter_words{};

    in_file.open("romeoandjuliet.txt");
    // in_file.open("deneme.txt");
    if(!in_file){
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::cout << "Enter the substring to search for: ";
    std::cin >> searched_word;
    size_t sizeOfSearchedWord{searched_word.size()};

    while (in_file >> word)
    {
        size_t sizeOfWord{word.size()};
        for (size_t j = 0; j < sizeOfWord; j++)
        {
            if(searched_word.at(0) == word.at(j))
                if(searched_word == word.substr(j, sizeOfSearchedWord))
                    ++counter_searched_word;
        }
        ++counter_words;
    }

    std::cout << "\n" << counter_words << " words were searched." << std::endl;
    std::cout << "The substring " << searched_word << " was found " << counter_searched_word << " times \n" << std::endl;

    in_file.close();
    std::cout << std::endl;

    return 0;
}









