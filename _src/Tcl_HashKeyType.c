#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_HashKeyType	*new_Tcl_HashKeyType(void)
{
	struct Tcl_HashKeyType	*new;

	if (!(new = (struct Tcl_HashKeyType*)malloc(sizeof(struct Tcl_HashKeyType))))
		return (NULL);
	new->version = 0;
	new->flags = 0;
	new->hashKeyProc = NULL;
	new->compareKeysProc = NULL;
	new->allocEntryProc = NULL;
	new->freeEntryProc = NULL;
	return (new);
}

struct Tcl_HashKeyType	*manage_Tcl_HashKeyType(int macro)
{
	static struct Tcl_HashKeyType	*current;

	if (macro == NEW)
		current = new_Tcl_HashKeyType();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_HashKeyType: no decent macro\n", 40);
	return (NULL);
}
