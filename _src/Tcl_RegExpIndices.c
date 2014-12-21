#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_RegExpIndices	*new_Tcl_RegExpIndices(void)
{
	struct Tcl_RegExpIndices	*new;

	if (!(new = (struct Tcl_RegExpIndices*)malloc(sizeof(struct Tcl_RegExpIndices))))
		return (NULL);
	new->start = 0;
	new->end = 0;
	return (new);
}

struct Tcl_RegExpIndices	*manage_Tcl_RegExpIndices(int macro)
{
	static struct Tcl_RegExpIndices	*current;

	if (macro == NEW)
		current = new_Tcl_RegExpIndices();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_RegExpIndices: no decent macro\n", 42);
	return (NULL);
}
