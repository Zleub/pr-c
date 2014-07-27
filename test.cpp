#include <iostream>
#include <string>
#include <fstream>

#include "folder.hpp"
#include "header_class.hpp"

using namespace std;

void	print_headers(Folder *inc, Header_class *array)
{
	int				i;

	i = 0;
	while (i < inc->size)
	{
		(array + i)->print_structs();
		i += 1;
	}
}

void	update(Folder *inc)
{
	int				i;
	Header_class	*array;

	i = 0;
	if (inc->array != NULL)
	{
		array = static_cast<Header_class*> (::operator new (sizeof(Header_class) * inc->size));
		while (i < inc->size)
		{
			// read_file((inc->array + i)->name.c_str());
			new (array + i) Header_class((inc->array + i)->name.c_str());
			i += 1;
		}
	}
	// print_headers(inc, array);
}

int		main(void)
{
	int i;
	Folder *tree;
	Folder *inc;
	Folder *src;

	inc = NULL;
	src = NULL;
	tree = new Folder(".");

	i = 0;
	while (i < tree->size)
	{
		if ((tree->array + i)->name == "./inc")
			inc = (tree->array + i);
		if ((tree->array + i)->name == "./src")
			src = (tree->array + i);
		i += 1;
	}
	if (inc != NULL && src != NULL)
	{
		update(inc);
	}
	else
		cout << "Not in project folder, you need inc and src as folder" << endl;
}
