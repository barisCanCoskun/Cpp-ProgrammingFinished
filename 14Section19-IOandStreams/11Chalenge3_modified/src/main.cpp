// Section 19
// Challenge 3 - Word Finder
#include<iostream>
#include<fstream>
#include<iomanip>

void match_words(std::string searched_word, std::string word);

int counter_searched_word{};

int main()
{
    std::ifstream in_file;
    std::string word;    
    std::string searched_word;
    int counter_words{};

    in_file.open("romeoandjuliet.txt");
    // in_file.open("deneme.txt");
    if(!in_file){
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::cout << "Enter the substring to search for: ";
    std::cin >> searched_word;

    while (in_file >> word)
    {
        match_words(searched_word, word);
        ++counter_words;
    }

    std::cout << "\n" << counter_words << " words were searched." << std::endl;
    std::cout << "The substring " << searched_word << " was found " << counter_searched_word << " times \n" << std::endl;
    std::cout << std::endl;

    in_file.close();

    return 0;
}

void match_words(std::string searched_word, std::string word)
{
    for (size_t j = 0; j < word.size(); j++)
    {
        if(searched_word.at(0) == word.at(j))
            if(searched_word == word.substr(j, searched_word.size()))
                ++counter_searched_word;
    }
}





