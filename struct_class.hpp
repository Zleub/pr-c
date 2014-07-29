#include <iostream>
#include <string>
#include <fstream>

// #include <cstring>

#include "var.hpp"

#define MAX_SIZE 80

using namespace std;

class Struct_class
{
public:

	// Ajout pointer_add et add_type;

	string content[MAX_SIZE];
	string name;
	string typedef_name;
	string pointer_add; // Mal nomme: next_add est mieux, le reste etant prev_add, etc...
	string name_add_method; // Nom de la methode add (circular, push_back, push_back_rev, etc...)

	int	add_type; // flag de la méthode add (ENUM)
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

	// if "*/" is found, function takes line+1 as argument
	void		get_add_type(string line, ifstream *myfile)
	{
		std::string::iterator	i;

		this->add_type = 0; // si !add_type, signifie que formattage du header attendait une methode ADD
		if ((signed)line.find("CIRCULAR") != -1)
		{
			this->name_add_method = "circular";
			this->add_type = 1;
		}
		else if ((signed)line.find("PUSH_BACK") != -1)
		{
			this->name_add_method = "push_back";
			this->add_type = 2;
		}
		else if ((signed)line.find("PUSH_BACK_DOUBLE") != -1)
		{
			this->name_add_method = "push_back_double";
			this->add_type = 3;
		}

		// Si methode il y a, recuperer les noms de variables dont elle a besoin
		// la forme est indiquee en exemple dans header.h
		if ((this->add_type != -1) && (i = (signed)(line+1).find("next=")) == -1)
		{
			// EXEMPLE
			cout << "PUSH_BACK method needs a pointer to next to work properly" << endl;
			return ;
		}
		i = i + 5;
		while (*i != '\n')
			this->pointer_add += *i;
		// MEME CHOSE POUR PREV, ETC...
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

	void		define()
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
		string function_add;
		function_add = "\tif (macro == ADD)\n\t\tadd_" + this->name_add_method + "_" + this->name;

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
			ptr->printing(myfile, content[i]);
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
			{
				*myfile << "\tfree(elem->" << ptr->name << ");" << endl;
				// *myfile << "\telem->" << ptr->name << " = NULL;" << endl;
			}
			i += 1;
		}

		*myfile << "\tfree_(elem);" << endl;
		*myfile << "\telem = NULL;" << endl;


		*myfile << "\treturn (NULL);" << endl;
		*myfile << "}" << endl << endl;
	}

	void		write_add(ofstream *myfile)
	{
		string function_name;
		function_name = function_type + "\t\t*add_" + this->name + "(" + this->function_type "*begin, " + this->function_type + " *elem)";

		*myfile << function_name << endl;

		*myfile << "{" << endl;

		// PUSH_BACK en exemple
		if (this->add_type == 2)
		{
			*myfile << "\t\tif (!begin)\n\t\t\tbegin = elem;\n\t\telse\n\t\t{\n\t\t\t";
			*myfile << "rem = begin;\n\t\t\twhile (rem->" + this->pointer_add + "))\n\t\t\t";
			*myfile << "while (rem->" + this->pointer_add + "))\n\t\t\t";
			*myfile << "\trem = rem->" + this->pointer_add + ";\n\t\t\t";
			*myfile << "rem = rem->" + this->pointer_add + ";\n\t\t\t}\n\t\t"
			*myfile << "return (begin);\n}";
		}
	}

	Struct_class(string line, ifstream *myfile)
	{
		this->name = line.substr(line.find("s_") + 2);
		cout << "Struct_class: \"" << this->name << "\" created" << endl;


		string str;

		str = "./src/" + this->name + ".c";
		ofstream struct_file(str.c_str());

		store(line, myfile);

		define();

		write_header(&struct_file);
		write_create(&struct_file);
		write_delete(&struct_file);
		write_manage(&struct_file);
		write_add(&struct_file);

	}
};
