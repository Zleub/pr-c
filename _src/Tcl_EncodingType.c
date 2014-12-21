#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_EncodingType	*new_Tcl_EncodingType(void)
{
	struct Tcl_EncodingType	*new;

	if (!(new = (struct Tcl_EncodingType*)malloc(sizeof(struct Tcl_EncodingType))))
		return (NULL);
	new->encodingName = NULL;
	new->toUtfProc = NULL;
	new->fromUtfProc = NULL;
	new->freeProc = NULL;
	new->clientData = 0;
	new->nullSize = 0;
	return (new);
}

struct Tcl_EncodingType	*manage_Tcl_EncodingType(int macro)
{
	static struct Tcl_EncodingType	*current;

	if (macro == NEW)
		current = new_Tcl_EncodingType();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_EncodingType: no decent macro\n", 41);
	return (NULL);
}
