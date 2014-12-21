#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_ConfigSpec	*new_Tk_ConfigSpec(void)
{
	struct Tk_ConfigSpec	*new;

	if (!(new = (struct Tk_ConfigSpec*)malloc(sizeof(struct Tk_ConfigSpec))))
		return (NULL);
	new->type = 0;
	new->argvName = NULL;
	new->dbName = 0;
	new->dbClass = 0;
	new->defValue = 0;
	new->offset = 0;
	new->specFlags = 0;
	new-> below = NULL;
	new->customPtr = NULL;
	return (new);
}

struct Tk_ConfigSpec	*manage_Tk_ConfigSpec(int macro)
{
	static struct Tk_ConfigSpec	*current;

	if (macro == NEW)
		current = new_Tk_ConfigSpec();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_ConfigSpec: no decent macro\n", 38);
	return (NULL);
}
