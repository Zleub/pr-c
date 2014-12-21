#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_CmdInfo	*new_Tcl_CmdInfo(void)
{
	struct Tcl_CmdInfo	*new;

	if (!(new = (struct Tcl_CmdInfo*)malloc(sizeof(struct Tcl_CmdInfo))))
		return (NULL);
	new->isNativeObjectProc = 0;
	new-> Tcl_CreateObjCommand = NULL;
	new->objProc = NULL;
	new->objClientData = 0;
	new->proc = NULL;
	new->clientData = 0;
	new->deleteProc = NULL;
	new->deleteData = 0;
	new->namespacePtr = NULL;
	new-> change a command's namespace = NULL;
	return (new);
}

struct Tcl_CmdInfo	*manage_Tcl_CmdInfo(int macro)
{
	static struct Tcl_CmdInfo	*current;

	if (macro == NEW)
		current = new_Tcl_CmdInfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_CmdInfo: no decent macro\n", 36);
	return (NULL);
}
