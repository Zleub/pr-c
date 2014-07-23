#include <iostream>
#include <string>

#include "struct_class.hpp"

using namespace std;

class Header_class
{
public:
	ifstream *myfile;
	int typedef_count;
	int struct_count;

void	is_option(string line)
{
	int		pos;

	if (this->typedef_count == 1)
	{
		pos = line.find("t_", 0);
		if (pos != -1)
		{
			cout << line.substr(pos, string::npos) << endl;
			this->typedef_count = 0;
		}
	}

	if (this->struct_count == 1)
	{
		pos = line.find("}", 0);
		if (pos != -1)
		{
							// cout << line.substr(pos, string::npos) << endl;
			cout << "end_struct" << endl;
			this->struct_count = 0;
		}
	}
}

void	make_option(string line)
{
	int		pos;

	pos = line.find("typedef", 0);
	if (pos != -1)
	{
		this->typedef_count = 1;
		cout << line.substr(pos, string::npos) << endl;
	}

	pos = line.find("struct", 0);
	if (pos != -1)
	{
		this->struct_count = 1;
		cout << line.substr(pos, string::npos) << endl;
	}

}


void	read_file()
{
	string line;

	if (this->myfile->is_open())
	{
		this->typedef_count = 0;
		this->struct_count = 0;

		while ( getline(*this->myfile, line))
		{

			this->is_option(line);

			this->make_option(line);
			// cout << line << endl;

		}
		cout << endl;
		this->myfile->close();
	}
}

	Header_class(const char *name)
	{
		cout << "Header_class: " << name << " created" << endl;
		myfile = new ifstream(name);
		this->read_file();
	}
};
