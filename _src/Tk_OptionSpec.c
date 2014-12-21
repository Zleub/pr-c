#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_OptionSpec	*new_Tk_OptionSpec(void)
{
	struct Tk_OptionSpec	*new;

	if (!(new = (struct Tk_OptionSpec*)malloc(sizeof(struct Tk_OptionSpec))))
		return (NULL);
	new->type = 0;
	new->optionName = NULL;
	new->dbName = NULL;
	new->dbClass = NULL;
	new->defValue = NULL;
	new->objOffset = 0;
	new->internalOffset = 0;
	new->flags = 0;
	new->clientData = 0;
	new->typeMask = 0;
	new-> manager = NULL;
	return (new);
}

struct Tk_OptionSpec	*manage_Tk_OptionSpec(int macro)
{
	static struct Tk_OptionSpec	*current;

	if (macro == NEW)
		current = new_Tk_OptionSpec();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_OptionSpec: no decent macro\n", 38);
	return (NULL);
}
