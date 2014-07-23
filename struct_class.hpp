#include <iostream>
#include <string>

using namespace std;

class Struct_class
{
public:
	ifstream *myfile;

	Struct_class(const char *name)
	{
		cout << "Struct_class: " << name << " created" << endl;
		myfile = new ifstream(name);
	}
};
