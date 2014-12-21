#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_SavedResult	*new_Tcl_SavedResult(void)
{
	struct Tcl_SavedResult	*new;

	if (!(new = (struct Tcl_SavedResult*)malloc(sizeof(struct Tcl_SavedResult))))
		return (NULL);
	new->result = NULL;
	new->freeProc = NULL;
	new->objResultPtr = NULL;
	new->appendResult = NULL;
	new->appendAvl = 0;
	new->appendUsed = 0;
	bzero((void*)(&new->resultSpace), sizeof(char) * TCL_RESULT_SIZE+1);
	return (new);
}

struct Tcl_SavedResult	*manage_Tcl_SavedResult(int macro)
{
	static struct Tcl_SavedResult	*current;

	if (macro == NEW)
		current = new_Tcl_SavedResult();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_SavedResult: no decent macro\n", 40);
	return (NULL);
}
