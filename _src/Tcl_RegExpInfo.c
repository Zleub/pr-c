#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_RegExpInfo	*new_Tcl_RegExpInfo(void)
{
	struct Tcl_RegExpInfo	*new;

	if (!(new = (struct Tcl_RegExpInfo*)malloc(sizeof(struct Tcl_RegExpInfo))))
		return (NULL);
	new->nsubs = 0;
	new->matches = NULL;
	new->extendStart = 0;
	new->reserved = 0;
	return (new);
}

struct Tcl_RegExpInfo	*manage_Tcl_RegExpInfo(int macro)
{
	static struct Tcl_RegExpInfo	*current;

	if (macro == NEW)
		current = new_Tcl_RegExpInfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_RegExpInfo: no decent macro\n", 39);
	return (NULL);
}
