#include <iostream>
#include <string>

#define MAX_SIZE 80

using namespace std;

class Struct_class
{
public:
	string content[MAX_SIZE];
	string name;
	string typedef_name;

	int typedef_bool;
	int array_size;

	void		print_struct()
	{
		cout << "Hay, this is print_struct: " << this->name << endl;
		cout << "typedef_bool: " << typedef_bool << endl;
		cout << "typedef_name: " << typedef_name << endl;

		cout << "array_size: " << array_size << endl;
		print_struct_content();
		cout << endl;
	}

	void		print_struct_content()
	{
		int		cmp;

		cmp = 0;
		while (cmp < MAX_SIZE && content[cmp] != "")
		{
			cout << "content[" << cmp << "] :" << content[cmp] << endl;
			cmp += 1;
		}
	}

	void		store(string line, ifstream *myfile) // get typedef, pointer & variable nbr
	{
		int		off;
		int		cmp;
		int		pos;

		if ((signed)line.find("typedef") != -1)
			this->typedef_bool = 1;
		else
			this->typedef_bool = 0;

		off = 0;
		cmp = 0;
		while (off == 0)
		{
			getline(*myfile, line);
			content[cmp] = line; // BEWARE OF CMP < MAX_SIZE
			if ((signed)line.find("}") != -1)
			{
				if ((pos = line.find("t_")) != -1)
					this->typedef_name = line.substr(pos + 2, line.length() - pos - 3);
				off = 1;
			}
			cmp += 1;
		}
		this->array_size = cmp - 2;


		cout << "array_size: " << cmp - 2 << endl;
	}

	void		write()
	{

	}

	Struct_class(string line, ifstream *myfile)
	{
		this->name = line.substr(line.find("s_") + 2);

		store(line, myfile);
		write();

		cout << "Struct_class: \"" << this->name << "\" created" << endl;
	}
};
