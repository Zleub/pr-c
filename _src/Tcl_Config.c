#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Config	*new_Tcl_Config(void)
{
	struct Tcl_Config	*new;

	if (!(new = (struct Tcl_Config*)malloc(sizeof(struct Tcl_Config))))
		return (NULL);
	new->key = NULL;
	new->value = NULL;
	return (new);
}

struct Tcl_Config	*manage_Tcl_Config(int macro)
{
	static struct Tcl_Config	*current;

	if (macro == NEW)
		current = new_Tcl_Config();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Config: no decent macro\n", 35);
	return (NULL);
}
