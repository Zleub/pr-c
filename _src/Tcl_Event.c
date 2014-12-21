#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Event	*new_Tcl_Event(void)
{
	struct Tcl_Event	*new;

	if (!(new = (struct Tcl_Event*)malloc(sizeof(struct Tcl_Event))))
		return (NULL);
	new->proc = NULL;
	new->nextPtr = NULL;
	return (new);
}

struct Tcl_Event	*manage_Tcl_Event(int macro)
{
	static struct Tcl_Event	*current;

	if (macro == NEW)
		current = new_Tcl_Event();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Event: no decent macro\n", 34);
	return (NULL);
}
