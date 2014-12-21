#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_SavedOption	*new_Tk_SavedOption(void)
{
	struct Tk_SavedOption	*new;

	if (!(new = (struct Tk_SavedOption*)malloc(sizeof(struct Tk_SavedOption))))
		return (NULL);
	new->optionPtr = NULL;
	new->valuePtr = NULL;
	new-> a Tcl object = NULL;
	new->internalForm = 0;
	new-> double, a long, or a pointer = NULL;
	return (new);
}

struct Tk_SavedOption	*manage_Tk_SavedOption(int macro)
{
	static struct Tk_SavedOption	*current;

	if (macro == NEW)
		current = new_Tk_SavedOption();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_SavedOption: no decent macro\n", 39);
	return (NULL);
}
