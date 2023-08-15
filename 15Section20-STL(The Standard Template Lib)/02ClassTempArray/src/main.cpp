// Section 20
// Class template - Array

// Note: Since C++11 the STL has std::array which is a template-based array class
// Use! std::array instead of RAW ayrays whenever possible

// Note that we can have non-type template params 
// That's what N is in this case

#include<iostream>
#include<vector>

// Making this template class generic with generic types of array elements
template<typename T, int N>
class Array
{
    int size{N};        // how do i get the N?
    T values[N];        // the N needs to be known at compile-time!

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
    {
        size_t i{};
        os << "[ ";
        for (const auto &v: arr.values)
            os << v << ((i++ != (N - 1)) ? ", " : " ");
        
        os << "]" << std::endl;
        return os;
    }

public:
    Array() = default;
    Array(T init_val){
        for(auto &item: values)
            item = init_val;
    }

    void fill(T val){
        for(auto &item: values)
            item = val;
    }

    int get_size() const{
        return size;
    }

    // Overloaded subscript operator for easy use. used as get_value()
    T &operator [](int index){
        return values[index];
    }    
};

int main()
{
    Array<int, 7> arr(5);
    arr[1] = 9;
    std::cout << arr[1] << std::endl;       // arr.operator[](1);

    arr.fill(12);
    std::cout << arr[1] << std::endl;

    std::cout << "\n=================================" << std::endl;
    Array<int, 3> arr1(1);
    std::vector<Array<int, 3>> vec;
    vec.push_back(arr1);
    std::cout << vec.at(0)[0] << ", " << vec.at(0)[1] << ", " << vec.at(0)[2] << std::endl;
    vec.push_back(Array<int, 3>(2));
    std::cout << vec.at(1)[0] << ", " << vec.at(1)[1] << ", " << vec.at(1)[2] << std::endl;
    vec.push_back(Array<int, 3>());
    std::cout << vec.at(2)[0] << ", " << vec.at(2)[1] << ", " << vec.at(2)[2] << std::endl;

    std::cout << "\n=================================" << std::endl;
    for (auto &v: vec){
        std::cout << v[0] << ", " << v[1] << ", " << v[2] << std::endl;
    }
    
    std::cout << "\n=================================" << std::endl;
    for (const auto &v: vec){
        std::cout << v << std::endl;
    }
    
    Array<int, 20> nums;
    std::cout << "\nThe size of nums is:" << nums.get_size() << std::endl;

    nums.fill(5);
    std::cout << nums << std::endl;

    nums[3] = 90;
    nums[5] = 70;
    nums[7] = 10;
    std::cout << nums << std::endl;

    Array<std::string, 5> strings;
    strings.fill("Boris");
    std::cout << strings << std::endl;

    strings[1] = "Can";
    std::cout << strings << std::endl;

    strings.fill("Can");
    std::cout << strings << std::endl;

    std::string my_string;
    if(my_string.empty())       // is the container empty?
        std::cout << "my string is empty" << std::endl;

    // my_string.insert('B');
    // std::cout << my_string.begin() << std::endl;

    return 0;
}









