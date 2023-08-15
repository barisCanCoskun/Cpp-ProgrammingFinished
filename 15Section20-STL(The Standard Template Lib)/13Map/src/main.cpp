#include<iostream>
#include<map>
#include<set>
#include<string>

template<typename T1, typename T2>
void display(const std::map<T1, T2> &map)
{
    std::cout << "[ ";
    for (const auto &m: map)
        std::cout << m.first << ": " << m.second << "  ";
    std::cout << "]" << std::endl;
}

void display(const std::map<std::string, std::set<int>> &map)
{
    std::cout << "[ ";
    for (const auto &m: map){
        std::cout << m.first << ": ";
        std::cout << "[ ";
        for(const auto &l: m.second)
            std::cout << l << " ";
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "Test1=====================" << std::endl;
    std::map<std::string, int> m{{"Rifki", 2}, {"Refik", 4}, {"Rambo", 6}};
    display(m);

    m.insert(std::pair<std::string, int>("Remzi", 8));
    display(m);

    m.insert(std::make_pair("Rojda", 3));
    display(m);

    m["Pars"] = 5;
    display(m);

    m.at("Refik") = 44;
    display(m);

    m.at("Rambo") += 4;
    display(m);

    m.erase("Rifki");
    display(m);

    auto p = m.find("Refik");
    if(p != m.end())
        std::cout << p->first << ": " << p->second << std::endl;

    m.clear();
    display(m);

}

void test2()
{
    std::cout << "Test2=====================" << std::endl;
    std::map<std::string, std::set<int>> m{{"Rifki", {2, 3, 5}}, {"Refik", {1, 7, 8}}, {"Rambo", {2, 4, 7}}};
    display(m);

    m.insert(std::pair<std::string, std::set<int>>("Remzi", {4, 5, 8}));
    display(m);

    m.insert(std::make_pair("Rojda", std::set<int>{3, 4, 6}));
    display(m);

    m["Pars"] = {5, 7, 8};
    display(m);

    m.at("Refik") = {2, 6, 8};
    display(m);

    m.at("Rambo").insert(5);
    display(m);

    m.erase("Rifki");
    display(m);

    auto p = m.find("Pars");
    if(p != m.end())
        p->second.emplace(9);
    
    display(m);

}

int main()
{
    // test1();
    test2();

    std::cout << std::endl;
    return 0;
}









