#include<iostream>
#include "Mystring.h"

using namespace std;

void display_test(Mystring obj)
{
    cout << "obj display func" << endl;
    obj.display();
}

int main()
{
	Mystring obj1;

    char test[]{"Test"};
    Mystring obj2{test};

    Mystring obj3{"Hi"};

    char *test1{nullptr};
    Mystring obj4{test1};

    Mystring obj5{obj3};

    display_test(obj3);

    cout << "obj2' s str: ";
    obj2.display(); 

    obj1 = obj2;        // obj1.operator=(obj2); 

    Mystring obj6;

    obj6 = Mystring{"Obj6"};

    Mystring obj7;
    obj7 = "Obj7";

    Mystring obj8{Mystring{"Obj8"}};

    Mystring obj9{"OBJECT9"};

    obj8 = -obj9;

    return 0;
}










