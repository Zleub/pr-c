#include <iostream>
#include <dirent.h>
#include <string>

using namespace std;

class		Folder
{
public:
	string	name;
	Folder	*array;
	int		size;

	void	fill_array()
	{
		DIR *dir;
		struct dirent *ent;
		int	i;

		i = 0;
		dir = opendir(this->name.c_str());
		if (this->size != 0)
		{
			this->array = static_cast<Folder*> (::operator new (sizeof(Folder) * this->size));
			while ((ent = readdir(dir)) != NULL)
			{
				if (ent->d_name[0] != '.')
				{
					new (this->array + i) Folder(this->name + "/" + ent->d_name);
					i += 1;
				}
			}
		}
		else
			this->array = NULL;
		closedir (dir);
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
			this->fill_array();
		}
	}
};
