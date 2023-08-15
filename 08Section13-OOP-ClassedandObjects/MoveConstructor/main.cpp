#include<iostream>
#include<vector>

using namespace std;

class Move
{
private:
	int *data;
	int test;

public:
	int get_data(){return *data;}
	void set_data(int x){this->test = x;}

	Move(int d);

	// Copy Constructor
	Move(const Move &);

	// Move Constructor
	Move( Move &&) noexcept;

	~Move();		// cannot be overloaded.
					// useful to release memory and other resources
};

Move::Move(int d){
	data = new int;
	*data = d;
	cout << "Constructor for: " << *data << endl;	
}

Move::Move(const Move &source)
	: Move{*(source.data)} {	
	cout << "Copy constructor - Deep copy for: " << *data << endl;	
}

// Move::Move(Move &&source)
// 	: Move{source} {	
// 	// *data = source;
// 	cout << "Move constructor" << endl;	
// }

Move::Move(Move &&source) noexcept
	: data{source.data} {	// like shallow copy 	
	source.data = nullptr;	// difference here from shallow copy: nulling raw pointer data member 
	cout << "Move constructor - moving resource: " << *data << endl;	
}

Move::~Move()
{
	if(data != nullptr)
		cout << "Destructor freeing data for: " << *data << endl;	
	else
		cout << "Destructor freeing data for nullptr" << endl;
	
	delete data;
}

void display_Move(Move p){
	cout << "data: " << p.get_data() << endl;
}

int main()
{	
	int x{100};

	int &l_ref = x;
	l_ref = 20;

	int &&r_ref = 50;
	r_ref = 60;

	x = r_ref;

	vector<Move> vec;
	vec.push_back(Move{10});
	vec.push_back(Move{40});

    return 0;
}










