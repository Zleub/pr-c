#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Namespace	*new_Tcl_Namespace(void)
{
	struct Tcl_Namespace	*new;

	if (!(new = (struct Tcl_Namespace*)malloc(sizeof(struct Tcl_Namespace))))
		return (NULL);
	new->name = NULL;
	new->fullName = NULL;
	new->clientData = 0;
	new->deleteProc = NULL;
	new->parentPtr = NULL;
	return (new);
}

struct Tcl_Namespace	*manage_Tcl_Namespace(int macro)
{
	static struct Tcl_Namespace	*current;

	if (macro == NEW)
		current = new_Tcl_Namespace();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Namespace: no decent macro\n", 38);
	return (NULL);
}
