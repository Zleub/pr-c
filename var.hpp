#include "pr-c.hpp"

using	namespace std;

class	var
{
public:
	string	type;
	string	name;

	int		pointer;

	string	var_return;

	char	*trim(string str)
	{
		char	*trimed;
		int		i;
		int		j;

		i = 0;
			while (isalnum(str[i]) == 0)
				i += 1;
			j = i;
			while (isalnum(str[j]) == 1)
				j += 1;
			trimed = strcpy((char*)malloc(j - i + 1), str.substr(i, j - i).c_str());
			return (trimed);
	}

	void	parsing(string declaration)
	{
		char *result = strcpy((char*)malloc(declaration.length()+1), declaration.c_str());
		char	*str;

		if (this->pointer == 1)
			str = strtok(result, "*");
		else
			str = strtok(result, "\t");
		while (str != NULL)
		{

			str = trim(str);
			type = str;
			str = strtok (NULL, "\t");
			str = trim(str);
			name = str;
			str = strtok (NULL, "\t");
			// if (str != NULL)
		}

		if (this->pointer)
			var_return = "NULL";
		else
			var_return = "-1";

	}

	void	printing(ofstream *myfile, string declaration)
	{
		this->parsing(declaration);

		*myfile << "\telem->" << name << " = " << var_return << ";" << endl;
		cout << "var: " << name << " written" << endl;
	}

	var(string declaration)
	{
		cout << "var declared" << endl;
		if ((signed)declaration.find("*") != -1)
			this->pointer = 1;
		else
			this->pointer = 0;

		// parsing(myfile, declaration);

		// 	str = strtok(result, "*");
		// 	while (str != NULL)
		// 	{
		// 		string test = str;
		// 		*myfile << "TYPE  \"" << test << "\"" << endl;
		// 		str = strtok (NULL, " ,.-");
		// 		*myfile << "NAME  \"" << str << "\"" << endl;
		// 		str = strtok (NULL, " ,.-");
		// 	}
		// }
		// else
		// {
		// 	str = strtok(result, "\t");
		// 	while (str != NULL)
		// 	{
		// 		*myfile << "TYPE  \"" << str << "\"" << endl;
		// 		str = strtok (NULL, " ,.-");
		// 		*myfile << "NAME  \"" << str << "\"" << endl;
		// 		str = strtok (NULL, " ,.-");
		// 	}
		// }
	}
};
