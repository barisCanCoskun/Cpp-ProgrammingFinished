#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Deep
{
private:
	int *data;

public:
	int get_data(){return *data;}

	Deep(int d);

	// Copy Constructor
	Deep(const Deep &);

	~Deep();		// cannot be overloaded.
					// useful to release memory and other resources
};

Deep::Deep(int d){
	data = new int;
	*data = d;
}

Deep::Deep(const Deep &source)
	: Deep{*(source.data)} {	
	cout << "Copy constructor - deep" << endl;	
}

Deep::~Deep()
{
	cout << "Destructor for " << *data << endl;	
	delete data;
}

void display_Deep(Deep p){
	cout << "data: " << p.get_data() << endl;
}

int main()
{	
	Deep pole{20};

	Deep north{pole};		// to Copy Constructor

	Deep south{30};
	display_Deep(south);		// to Copy Constructor

    return 0;
}










