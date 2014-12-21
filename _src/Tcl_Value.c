#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Value	*new_Tcl_Value(void)
{
	struct Tcl_Value	*new;

	if (!(new = (struct Tcl_Value*)malloc(sizeof(struct Tcl_Value))))
		return (NULL);
	new->type = 0;
	new->intValue = 0;
	new->doubleValue = 0;
	new->wideValue = 0;
	return (new);
}

struct Tcl_Value	*manage_Tcl_Value(int macro)
{
	static struct Tcl_Value	*current;

	if (macro == NEW)
		current = new_Tcl_Value();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Value: no decent macro\n", 34);
	return (NULL);
}
