#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_ChannelType	*new_Tcl_ChannelType(void)
{
	struct Tcl_ChannelType	*new;

	if (!(new = (struct Tcl_ChannelType*)malloc(sizeof(struct Tcl_ChannelType))))
		return (NULL);
	new->typeName = NULL;
	new->version = 0;
	new->closeProc = NULL;
	new->inputProc = NULL;
	new->outputProc = NULL;
	new->seekProc = NULL;
	new->setOptionProc = NULL;
	new->getOptionProc = NULL;
	new->watchProc = NULL;
	new->getHandleProc = NULL;
	new->close2Proc = NULL;
	new->blockModeProc = NULL;
	new->flushProc = NULL;
	new->handlerProc = NULL;
	new->wideSeekProc = NULL;
	new->threadActionProc = NULL;
	new->truncateProc = NULL;
	return (new);
}

struct Tcl_ChannelType	*manage_Tcl_ChannelType(int macro)
{
	static struct Tcl_ChannelType	*current;

	if (macro == NEW)
		current = new_Tcl_ChannelType();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_ChannelType: no decent macro\n", 40);
	return (NULL);
}
