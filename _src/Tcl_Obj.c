#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Obj	*new_Tcl_Obj(void)
{
	struct Tcl_Obj	*new;

	if (!(new = (struct Tcl_Obj*)malloc(sizeof(struct Tcl_Obj))))
		return (NULL);
	new->refCount = 0;
	new->bytes = NULL;
	new->length = 0;
	new->typePtr = NULL;
	new->longValue = 0;
	new->doubleValue = 0;
	new->otherValuePtr = NULL;
	new->wideValue = 0;
	new->ptr1 = NULL;
	new->ptr2 = NULL;
	return (new);
}

struct Tcl_Obj	*manage_Tcl_Obj(int macro)
{
	static struct Tcl_Obj	*current;

	if (macro == NEW)
		current = new_Tcl_Obj();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Obj: no decent macro\n", 32);
	return (NULL);
}
