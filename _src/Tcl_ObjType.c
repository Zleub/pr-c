#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_ObjType	*new_Tcl_ObjType(void)
{
	struct Tcl_ObjType	*new;

	if (!(new = (struct Tcl_ObjType*)malloc(sizeof(struct Tcl_ObjType))))
		return (NULL);
	new->name = NULL;
	new->freeIntRepProc = NULL;
	new->dupIntRepProc = NULL;
	new->updateStringProc = NULL;
	new->setFromAnyProc = NULL;
	return (new);
}

struct Tcl_ObjType	*manage_Tcl_ObjType(int macro)
{
	static struct Tcl_ObjType	*current;

	if (macro == NEW)
		current = new_Tcl_ObjType();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_ObjType: no decent macro\n", 36);
	return (NULL);
}
