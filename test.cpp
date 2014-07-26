#include <iostream>
#include <string>
#include <fstream>

#include "folder.hpp"
#include "header_class.hpp"

using namespace std;

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
	// i = 0;
	// while (i < inc->size)
	// {
	// 	(array + i)->print_structs();
	// 	i += 1;
	// }
}

int		main(void)
{
	int i;
	Folder *ptr;
	Folder *inc;
	Folder *src;

	inc = NULL;
	src = NULL;
	ptr = new Folder(".");

	i = 0;
	while (i < ptr->size)
	{
		if ((ptr->array + i)->name == "./inc")
			inc = (ptr->array + i);
		if ((ptr->array + i)->name == "./src")
			src = (ptr->array + i);
		i += 1;
	}
	if (inc != NULL && src != NULL)
	{
		update(inc);
	}
	else
		cout << "Not in project folder, you need inc and src as folder" << endl;
}
