#include<iostream>
#include<queue>
#include<vector>
#include<list>

template<typename T>
void display(std::queue<T> q)
{
    std::cout << "[ ";
    while(!q.empty()){
        T elem{q.front()};
        q.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::queue<int> q;

    for(int i: {1, 2, 3, 4, 5})
        q.emplace(i);
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while(!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;

    q.emplace(10);
    q.emplace(100);
    display(q);

    q.front() = 20;
    q.back() = 40;
    display(q);

    return 0;
}









