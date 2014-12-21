#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_DString	*new_Tcl_DString(void)
{
	struct Tcl_DString	*new;

	if (!(new = (struct Tcl_DString*)malloc(sizeof(struct Tcl_DString))))
		return (NULL);
	new->string = NULL;
	new->length = 0;
	new->spaceAvl = 0;
	bzero((void*)(&new->staticSpace), sizeof(char) * TCL_DSTRING_STATIC_SIZE);
	return (new);
}

struct Tcl_DString	*manage_Tcl_DString(int macro)
{
	static struct Tcl_DString	*current;

	if (macro == NEW)
		current = new_Tcl_DString();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_DString: no decent macro\n", 36);
	return (NULL);
}
