#include<iostream>
#include<string>

using namespace std;

class Shallow
{
private:
	int *data;

public:
	Shallow(int d){
		data = new int;
		*data = d;
	}

	int get_data(){return *data;}

	// Copy Constructor
	Shallow(const Shallow &);

	~Shallow();		// cannot be overloaded.
					// useful to release memory and other resources
};

Shallow::Shallow(const Shallow &source)
	: data{source.data} {	
	cout << "Copy constructor - shallow" << endl;	
}

Shallow::~Shallow()
{
	cout << "Destructor for " << data << endl;	
}

void display_Shallow(Shallow p){
	cout << "data: " << p.get_data() << endl;
}

int main()
{	
	Shallow pole{20};

	Shallow north{pole};		// to Copy Constructor

	Shallow south{30};
	display_Shallow(south);		// to Copy Constructor

    return 0;
}










