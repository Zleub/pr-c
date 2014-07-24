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

	int struct_nbr;

	Struct_class *struct_array;

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
			cout << " RTEST " << line.substr(pos, string::npos) << endl;
			// this->struct_class = new Struct_class(line.c_str());
		}

	}

	void	create_struct_class(int nbr, string line)
	{
		int pos;

		pos = line.find("s_");
		// cout << "\"" << line.substr(pos) << "\"" << endl;
		new (this->struct_array + nbr) Struct_class(line.substr(pos).c_str());
	}

	void	read_file()
	{
		int nbr;
		string line;

		if (this->myfile->is_open())
		{
			// this->typedef_count = 0;
			// this->struct_count = 0;
			nbr = 0;
			this->struct_array = static_cast<Struct_class*> (::operator new (sizeof(Struct_class[this->struct_nbr])));

			while ( getline(*this->myfile, line))
			{

				// this->is_option(line);

				// this->make_option(line);
			// cout << line << endl;
				if ((signed)line.find("struct") != -1)
				{
					create_struct_class(nbr, line);
					nbr += 1;
				}
			}
			cout << endl;
		}
	}

	void	count_file()
	{
		string line;

		this->struct_nbr = 0;
		while (getline(*this->myfile, line))
		{
			if ((signed)line.find("struct") != -1)
				this->struct_nbr += 1;
		}
		cout << "struct_nbr: " << struct_nbr << endl;
	}

	void		print_structs()
	{
		int		i;

		i = 0;
		while (i < this->struct_nbr)
		{
			(this->struct_array + i)->print_struct();
			i += 1;
		}
	}

	Header_class(const char *name)
	{
		cout << "Header_class: " << name << " created" << endl;
		myfile = new ifstream(name);
		this->count_file();
		this->myfile->close();
		myfile = new ifstream(name);
		this->read_file();
		this->myfile->close();
	}
};
