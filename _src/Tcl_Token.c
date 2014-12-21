#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Token	*new_Tcl_Token(void)
{
	struct Tcl_Token	*new;

	if (!(new = (struct Tcl_Token*)malloc(sizeof(struct Tcl_Token))))
		return (NULL);
	new->type = 0;
	new->start = NULL;
	new->size = 0;
	new->numComponents = 0;
	return (new);
}

struct Tcl_Token	*manage_Tcl_Token(int macro)
{
	static struct Tcl_Token	*current;

	if (macro == NEW)
		current = new_Tcl_Token();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Token: no decent macro\n", 34);
	return (NULL);
}
