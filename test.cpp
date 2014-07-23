#include <iostream>
#include <dirent.h>
#include <string>

using namespace std;

class Folder
{
public:
	string name;
	Folder *array;
	int size;

	Folder(string name): name(name)
	{
		DIR *dir;
		struct dirent *ent;
		int	i;

		i = 0;
		if ((dir = opendir(this->name.c_str())) != NULL)
		{
			while ((ent = readdir(dir)) != NULL)
			{
				if (ent->d_name[0] != '.')
					i += 1;
			}
			closedir (dir);
			this->size = i;
		}
		this->fill_array();
	}

	void	fill_array()
	{

		DIR *dir;
		struct dirent *ent;
		int	i;

		i = 0;
		if ((dir = opendir(this->name.c_str())) != NULL)
		{
			this->array = static_cast<Folder*> (::operator new (sizeof(Folder[this->size])));
			while ((ent = readdir(dir)) != NULL)
			{
				if (ent->d_name[0] != '.')
				{
					new (this->array + i) Folder(this->name + "/" + ent->d_name);
					i += 1;
				}
			}
			closedir (dir);
		}
	}

	void	print_array()
	{
		int i;

		i = 0;
		cout << this->name << endl;
		while (i < this->size)
		{
			(this->array + i)->print_array();
			i += 1;
		}
	}

};

int		main(void)
{
	Folder *ptr;
	int i;
	char inc;
	char src;

	inc = 0;
	src = 0;
	ptr = new Folder(".");

	i = 0;
	while (i < ptr->size)
	{
		if ((ptr->array + i)->name == "./inc" && (ptr->array + i)->array != NULL)
			inc = 1;
		if ((ptr->array + i)->name == "./src")
			src = 1;
		i += 1;
	}
	cout << "inc: " << int(inc) << ", src:" << int(src) << endl;
}

