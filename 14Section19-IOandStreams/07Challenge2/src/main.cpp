// Section 19
// Challenge 2 - Automated Grader
// Section 19
#include<iostream>
#include<fstream>
#include<iomanip>

int main()
{
    std::ifstream in_file;
    std::string name{};
    std::string response{};
    std::string correct_response{"ABCDE"};
    int counter_cor_response{};
    int i{};
    int total_cor_responses{};
    int total_students{};

    in_file.open("responses.txt");
    if(!in_file){
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    // while (!in_file.eof())
    // {
    //     in_file >> line >> num >> total;
    //     std::cout << std::setw(10) << std::left << line
    //               << std::setw(10) << num 
    //               << std::setw(10) << total << std::endl;
    // }

    std::cout << std::setw(15) << std::left << "Student";
    std::cout << std::setw(10) << std::right << "Score" << std::endl;
    std::cout << std::setfill('-') << std::setw(25) << "" << std::endl;

    std::cout << std::setfill(' ');

    while (in_file >> name >> response)
    {
        std::cout << std::setw(15) << std::left << name;
        total_students++;
        for (const auto &c : response)
        {
            if(c == correct_response.at(i++))
                counter_cor_response++;
        }

        i = 0;
        std::cout << std::setw(8) << std::right << counter_cor_response << std::endl;
        total_cor_responses += counter_cor_response;
        counter_cor_response = 0;
        
    }

    std::cout << std::setfill('-') << std::setw(25) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(15) << std::left << "Average Score";
    std::cout << std::setw(8) << std::right << static_cast<double>(total_cor_responses) / total_students << std::endl;

    in_file.close();
    std::cout << std::endl;

    return 0;
}



















