#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_HashEntry	*new_Tcl_HashEntry(void)
{
	struct Tcl_HashEntry	*new;

	if (!(new = (struct Tcl_HashEntry*)malloc(sizeof(struct Tcl_HashEntry))))
		return (NULL);
	new->nextPtr = NULL;
	new->tablePtr = NULL;
	new->hash = NULL;
	new->*bucketPtr = NULL;
	new->clientData = 0;
	new->oneWordValue = NULL;
	new->objPtr = NULL;
	bzero((void*)(&new->words), sizeof(int) * 1);
	bzero((void*)(&new->string), sizeof(char) * 4);
	return (new);
}

struct Tcl_HashEntry	*manage_Tcl_HashEntry(int macro)
{
	static struct Tcl_HashEntry	*current;

	if (macro == NEW)
		current = new_Tcl_HashEntry();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_HashEntry: no decent macro\n", 38);
	return (NULL);
}
