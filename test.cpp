#include <iostream>
#include <dirent.h>
#include <string>
#include <fstream>

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
			this->fill_array();
		}
	}

	void	fill_array()
	{
		DIR *dir;
		struct dirent *ent;
		int	i;

		i = 0;
		dir = opendir(this->name.c_str());
		if (this->size != 0)
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

};

void	update(Folder *inc, Folder *src)
{
	int i;


	i = 0;
	if (inc->array != NULL)
	{
		while (i < inc->size)
		{
			cout << (inc->array + i)->name.c_str() << endl;

			ifstream myfile ((inc->array + i)->name.c_str());
			string line;

			if (myfile.is_open())
			{
				int typedef_count;
				int struct_count;

				typedef_count = 0;
				struct_count = 0;

				while ( getline (myfile, line))
				{
					int fd;

					if (typedef_count == 1)
					{
						fd = line.find("t_", 0);
						if (fd != -1)
						{
							cout << line.substr(fd, string::npos) << endl;
							typedef_count = 0;
						}
					}

					if (struct_count == 1)
					{
						fd = line.find("}", 0);
						if (fd != -1)
						{
							// cout << line.substr(fd, string::npos) << endl;
							cout << "end_struct" << endl;
							struct_count = 0;
						}
					}




					fd = line.find("typedef", 0);
					if (fd != -1)
					{
						typedef_count = 1;
						cout << line.substr(fd, string::npos) << endl;
					}

					fd = line.find("struct", 0);
					if (fd != -1)
					{
						struct_count = 1;
						cout << line.substr(fd, string::npos) << endl;
					}


					// cout << fd << endl;
				}
				myfile.close();
				i += 1;
			}
		}
	}
	if (src->array != NULL)
		cout << "2";
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
		update(inc, src);
	else
		cout << "Not in project folder" << endl;
}

