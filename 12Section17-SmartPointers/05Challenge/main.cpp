// Section 17
// Challenge
#include<iostream>
#include<memory>
#include<vector>

class Test
{
private:
    int data;
public:
    Test() :data{0} {std::cout << "Test ctor (" << data << ") " << std::endl; }
    Test(int d) :data{d} {std::cout << "\tInt arg Test ctor (" << data << ") " << std::endl; }
    int get_data() const {return data;}
    ~Test() {std::cout << "Test dtor (" << data << ") " << std::endl; }
};

// Func prototypes
// std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
// auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, size_t num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

auto make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();

    std::cout << "How many data points do u want to enter: ";
    int num;
    std::cin >> num;

    fill(*vec_ptr, num);
    display(*vec_ptr);

    return 0;
}

// std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
// {
//     return std::make_unique<std::vector<std::shared_ptr<Test>>>();
// }

void fill(std::vector<std::shared_ptr<Test>> &vec, size_t num)
{
    int data_point;
    for (size_t i{1}; i <= num; i++)
    {
        std::cout << "Enter data point [" << i << "] :";
        std::cin >> data_point;
        vec.push_back(std::make_shared<Test>(data_point));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
    std::cout << "Displaying vector data" << std::endl;
    std::cout << "=======================" << std::endl;
    for (const auto &p: vec)
    {
        std::cout << p->get_data() << std::endl;
    }
    std::cout << "=======================" << std::endl;
}













