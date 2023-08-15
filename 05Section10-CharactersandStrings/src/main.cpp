#include<iostream>
// #include<string.h>
#include<cstring>
#include<cctype>

using namespace std;

int main()
{
    char myName[]{"Baris Can"};         // C-style string

    cout << myName << endl;

    char myName1[8];

    // myName1 = "Baris";              // Error 

    strcpy(myName1, "Baris");       // OK

    cout << "\n" << myName1 << endl;

    char firstName[20]{};
    char fullName[40]{};

    cout << "\nFirst name: " << firstName << endl;

    strcpy(firstName, myName1);
    cout << "\nYour first name has " << strlen(firstName) << " characters." << endl;

    cout << "\nEnter your full name: " << endl; 
    cin.getline(fullName, 40);

    cout << "\nFull name: " << fullName << endl;

    for (size_t i = 0; i < strlen(fullName); i++)
    {
        if (isalpha(fullName[i]))
        {
            fullName[i] = toupper(fullName[i]);
        }
        
    }

    cout << "\nAfter toupper func, Full name: " << fullName << endl;
    

    return 0;
    
}