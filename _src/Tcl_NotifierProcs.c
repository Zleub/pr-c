#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_NotifierProcs	*new_Tcl_NotifierProcs(void)
{
	struct Tcl_NotifierProcs	*new;

	if (!(new = (struct Tcl_NotifierProcs*)malloc(sizeof(struct Tcl_NotifierProcs))))
		return (NULL);
	new->setTimerProc = NULL;
	new->waitForEventProc = NULL;
	new->createFileHandlerProc = NULL;
	new->deleteFileHandlerProc = NULL;
	new->initNotifierProc = NULL;
	new->finalizeNotifierProc = NULL;
	new->alertNotifierProc = NULL;
	new->serviceModeHookProc = NULL;
	return (new);
}

struct Tcl_NotifierProcs	*manage_Tcl_NotifierProcs(int macro)
{
	static struct Tcl_NotifierProcs	*current;

	if (macro == NEW)
		current = new_Tcl_NotifierProcs();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_NotifierProcs: no decent macro\n", 42);
	return (NULL);
}
