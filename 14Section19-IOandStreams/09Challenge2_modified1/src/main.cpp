// Section 19
// Challenge 2 - Automated Grader
// Section 19
#include<iostream>
#include<fstream>
#include<iomanip>

void print_header();
int process_response(const std::string &response, const std::string &correct_response);
void print_student(std::string name, int score);
void print_footer(double average_score);

int main()
{
    std::ifstream in_file;
    std::string name{};  
    std::string response;                    //Empty : C++ strings are always initialized.
    std::string correct_response;     
    int total_cor_responses{};
    int total_students{};
    double average_score{};

    in_file.open("responses.txt");
    if(!in_file){
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    print_header();

    in_file >> correct_response;

    while (in_file >> name >> response)
    {
        ++total_students;
        int score = process_response(response, correct_response);
        total_cor_responses += score;
        print_student(name, score);
    }

    if(total_students != 0)
        average_score = static_cast<double>(total_cor_responses) / total_students;

    print_footer(average_score);

    in_file.close();
    return 0;
}

int process_response(const std::string &response, const std::string &correct_response)
{
    size_t sizeOfCorRes{correct_response.size()};
    int counter_cor_response{};

    for (size_t i = 0; i < sizeOfCorRes; i++)
    {
        if(response.at(i) == correct_response.at(i))
            ++counter_cor_response;
    }

    return counter_cor_response;
}

void print_student(const std::string &name, int score)
{
    std::cout << std::setw(15) << std::left << name;
    std::cout << std::setw(8) << std::right << score << std::endl;  
}

void print_header()
{
    std::cout << std::setw(15) << std::left << "Student";
    std::cout << std::setw(10) << std::right << "Score" << std::endl;
    std::cout << std::setfill('-') << std::setw(25) << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer(double average_score)
{
    std::cout << std::setfill('-') << std::setw(25) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(15) << std::left << "Average Score";
    std::cout << std::setw(8) << std::right << average_score << std::endl;
    std::cout << std::endl;
}



















