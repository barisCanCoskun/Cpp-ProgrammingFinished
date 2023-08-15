// Section 20
// Class Temps
#include<iostream>
#include<vector>
#include<utility>

// only modeling data in this case
template<class f1, class f2>
struct My_pair
{
    f1 first;
    f2 second;
};

// Template classes should be contained in header files
template<class f>
class Item
{
private:
    std::string name;
    f value;
public:
    Item(std::string n, f val)
        : name{n}, value{val} {}
    std::string get_name() const {return name;}
    f get_value() const {return value;}
};


int main()
{
    Item<int> item1{"Item1", 23};
    std::cout << item1.get_name() << std::endl;

    Item<std::string> item2{"Item2", "What"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;
    
    Item<Item<std::string>> item3{"Boris", {"What", "u say"}};
    std::cout << item3.get_name() << " " 
              << item3.get_value().get_name() << " " 
              << item3.get_value().get_value() << std::endl;

    std::cout << "=================================" << std::endl;
    std::vector<Item<double>> vec{};
    vec.push_back({"Joe", 56.7});
    vec.push_back(Item<double>("Giovanni", 12.3));

    for (const auto &item: vec)
    {
        std::cout << item.get_name() << " " << item.get_value() << std::endl;
    }
    
    std::cout << "\n=================================" << std::endl;
    std::pair<std::string, int> pair1{"Haci", 72};
    std::cout << "pair1.first: " << pair1.first << std::endl;
    std::cout << "pair1.second: " << pair1.second << std::endl;

    My_pair<std::string, int> p1{"Veli", 56};
    
    My_pair<double, char> p2{45.6, 'B'};
    std::cout << "p2.first: " << p2.first << std::endl;

    std::vector<My_pair<int, double>> vec_my_pair;

    // std::tuple<int, double, char, std::string> tuple1{7, 34.01, 'B', "Boris"};

    std::cout << std::endl;
    return 0;
}









 