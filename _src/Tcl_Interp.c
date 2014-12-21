#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Interp	*new_Tcl_Interp(void)
{
	struct Tcl_Interp	*new;

	if (!(new = (struct Tcl_Interp*)malloc(sizeof(struct Tcl_Interp))))
		return (NULL);
	new->result = NULL;
	new->freeProc) _ANSI_ARGS_((char *blockPtr)) = NULL;
	new->errorLine = 0;
	return (new);
}

struct Tcl_Interp	*manage_Tcl_Interp(int macro)
{
	static struct Tcl_Interp	*current;

	if (macro == NEW)
		current = new_Tcl_Interp();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Interp: no decent macro\n", 35);
	return (NULL);
}
