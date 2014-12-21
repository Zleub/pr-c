#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_ObjCustomOption	*new_Tk_ObjCustomOption(void)
{
	struct Tk_ObjCustomOption	*new;

	if (!(new = (struct Tk_ObjCustomOption*)malloc(sizeof(struct Tk_ObjCustomOption))))
		return (NULL);
	new->name = NULL;
	new->setProc = NULL;
	new->getProc = NULL;
	new->restoreProc = NULL;
	new->freeProc = NULL;
	new->clientData = 0;
	return (new);
}

struct Tk_ObjCustomOption	*manage_Tk_ObjCustomOption(int macro)
{
	static struct Tk_ObjCustomOption	*current;

	if (macro == NEW)
		current = new_Tk_ObjCustomOption();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_ObjCustomOption: no decent macro\n", 43);
	return (NULL);
}
