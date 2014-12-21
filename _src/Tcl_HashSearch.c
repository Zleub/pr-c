#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_HashSearch	*new_Tcl_HashSearch(void)
{
	struct Tcl_HashSearch	*new;

	if (!(new = (struct Tcl_HashSearch*)malloc(sizeof(struct Tcl_HashSearch))))
		return (NULL);
	new->tablePtr = NULL;
	new->nextIndex = 0;
	new->nextEntryPtr = NULL;
	return (new);
}

struct Tcl_HashSearch	*manage_Tcl_HashSearch(int macro)
{
	static struct Tcl_HashSearch	*current;

	if (macro == NEW)
		current = new_Tcl_HashSearch();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_HashSearch: no decent macro\n", 39);
	return (NULL);
}
