#include <iostream>
#include <string>
#include <fstream>

#include <cstring>
#include "var.hpp"

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

	string function_type;

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


		cout << "array_size (var_size): " << cmp - 2 << endl;
	}

	void		get_define()
	{
		if (this->typedef_bool == 1)
			this->function_type = "t_" + this->typedef_name;
		else
			this->function_type = "struct s_" + this->name;
	}

	void		write_manage(ofstream *myfile)
	{
		string function_params;
		function_params = "int macro, " + function_type + " *object";

		string function_name;
		function_name = "manage_" + this->name + "(" + function_params + ")";

		*myfile << function_type << "\t\t*" << function_name << endl;

		*myfile << "{" << endl;

		string function_static;
		function_static = "\tstatic " + function_type + "\t*elem;";

		*myfile << function_static << endl << endl;

		string function_get;
		function_get = "\tif (macro == GET)\n\t\treturn (elem);";
		string function_set;
		function_set = "\tif (macro == SET)\n\t\telem = object;";
		string function_new;
		function_new = "\tif (macro == NEW)\n\t\telem = create_" + this->name + "();";
		string function_del;
		function_del = "\tif (macro == DEL)\n\t\telem = free_" + this->name + "(elem);";

		*myfile << function_get << endl;
		*myfile << function_set << endl;
		*myfile << function_new << endl;
		*myfile << function_del << endl;

		*myfile << "\treturn (NULL);" << endl;
		*myfile << "}" << endl;
	}

	void		write_header(ofstream *myfile)
	{
		*myfile << "/*\n** header\n*/\n" << endl;
	}

	void		write_create(ofstream *myfile)
	{
		string function_name;
		function_name = function_type + "\t\t*create_" + this->name + "(void)";

		*myfile << function_name << endl;

		*myfile << "{" << endl;

		string function_var;
		function_var = "\t" + function_type + "\t*elem;";

		*myfile << function_var << endl << endl;;

		string function_malloc;
		function_malloc = "\tif (!(elem = (" + this->function_type + "*)malloc(sizeof(" + this->function_type + "))))\n\t\treturn(NULL);";

		*myfile << function_malloc << endl;

		int i;

		i = 1;
		while (i <= this->array_size)
		{
			var *ptr;
			ptr = new var(content[i]);
			ptr->print_var_init(myfile, content[i]);
			i += 1;
		}

		*myfile << "\treturn (elem);" << endl;
		*myfile << "}" << endl << endl;

	}

	void		write_delete(ofstream *myfile)
	{
		string function_name;
		function_name = function_type + "\t\t*free_" + this->name + "(" + this->function_type + " *elem)";

		*myfile << function_name << endl;

		*myfile << "{" << endl;

		int i;

		i = 1;
		while (i <= this->array_size)
		{
			var *ptr;
			ptr = new var(content[i]);
			ptr->parsing(content[i]);
			if (ptr->pointer)
				*myfile << "\tfree(elem->" << ptr->name << ");" << endl;
			i += 1;
		}

		*myfile << "\tfree_(elem);" << endl;
		*myfile << "\telem = NULL;" << endl;


		*myfile << "\treturn (NULL);" << endl;
		*myfile << "}" << endl << endl;
	}

	Struct_class(string line, ifstream *myfile)
	{
		this->name = line.substr(line.find("s_") + 2);
		cout << "Struct_class: \"" << this->name << "\" created" << endl;


		string str;

		str = "./src/" + this->name + ".c";
		ofstream struct_file(str.c_str());

		store(line, myfile);

		get_define();

		write_header(&struct_file);
		write_create(&struct_file);
		write_delete(&struct_file);
		write_manage(&struct_file);

	}
};
