#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_GlobTypeData	*new_Tcl_GlobTypeData(void)
{
	struct Tcl_GlobTypeData	*new;

	if (!(new = (struct Tcl_GlobTypeData*)malloc(sizeof(struct Tcl_GlobTypeData))))
		return (NULL);
	new->type = 0;
	new->perm = 0;
	new->macType = NULL;
	new->macCreator = NULL;
	return (new);
}

struct Tcl_GlobTypeData	*manage_Tcl_GlobTypeData(int macro)
{
	static struct Tcl_GlobTypeData	*current;

	if (macro == NEW)
		current = new_Tcl_GlobTypeData();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_GlobTypeData: no decent macro\n", 41);
	return (NULL);
}
