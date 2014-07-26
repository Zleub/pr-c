#include <iostream>
#include <string>

#include "struct_class.hpp"

using namespace std;

class				Header_class
{
public:
	ifstream		*myfile;
	int				struct_nbr;

	Struct_class	*struct_array;

	void	create_struct_class(int nbr, string line)
	{
		new (this->struct_array + nbr) Struct_class(line, this->myfile);
	}

	void	read_file()
	{
		int nbr;
		string line;

		if (this->myfile->is_open())
		{
			nbr = 0;
			this->struct_array = static_cast<Struct_class*> (::operator new (sizeof(Struct_class) * this->struct_nbr));

			while ( getline(*this->myfile, line))
			{
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
