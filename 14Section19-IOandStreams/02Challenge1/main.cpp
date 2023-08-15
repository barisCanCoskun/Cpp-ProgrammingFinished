// Section 19
// Chalenge 1
// Formatting output

#include<iostream>
#include<iomanip>       
#include<vector>

void ruler()
{
    std::cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
}

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours{
        "Tour de Paris", { {"Russia", {
                                        {"Moscow", 12000000, 750},
                                        {"St. Petersburg", 7000000, 800},
                                        {"Stalingrad", 1500000, 350}
                                    }
                            },
                            {"Japan",{
                                        {"Tokyo", 15000000, 1000},
                                        {"Hiroshima", 2500000, 900}
                                    }
                            }
                        }
    };

    ruler();

    std::cout << std::setfill(' ') << std::setw(40) << tours.title << std::endl;

    std::cout << std::setw(20) << std::left << "Country";
    std::cout << std::setw(25) << std::left << "City";
    std::cout << std::setw(20) << std::left << "Population";
    std::cout << std::setw(20) << std::left << "Price" << std::endl;

    std::cout << std::setfill('*') << std::setw(70) << "" << std::endl;

    std::cout << std::setfill(' ');

    // BENİM YÖNTEM
    // for (const auto &country: tours.countries)
    // {
    //     std::cout << std::setw(20) << std::left << country.name;
    //     for (const auto &city: country.cities)
    //     {
    //         std::cout << std::setw(20) << std::left << city.name;
    //         std::cout << std::setw(15) << std::right << city.population;
    //         std::cout << std::setw(15) << std::right << city.cost << std::endl;
    //         std::cout << std::setw(20) << " ";
    //     }
    //     std::cout << std::endl;
    // }
    
    for (const auto &country: tours.countries)
    {
        for (size_t i{0}; i < country.cities.size(); i++)
        {
            std::cout << std::setw(20) << std::left << ((i == 0) ? country.name : "");      // conditional operator
            std::cout << std::setw(20) << std::left << country.cities.at(i).name;
            std::cout << std::setw(15) << std::right << country.cities.at(i).population;
            std::cout << std::setw(15) << std::right << country.cities.at(i).cost << std::endl;
        }
    }

    std::cout << std::endl;
    return 0;
}









