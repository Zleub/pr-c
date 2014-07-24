#include <iostream>
#include <string>

using namespace std;

class Struct_class
{
public:
	string name;

	void		print_struct()
	{
		cout << "Hay, this is print_struct: " << this->name << endl;
	}

	Struct_class(const char *name)
	{
		this->name = name;
		cout << "Struct_class: \"" << this->name << "\" created" << endl;
	}
};
