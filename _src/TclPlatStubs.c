#include <stdlib.h>
#include <string.h>
#include <tclPlatDecls.h>

enum e_macro
{
	NEW,
	GET
};

struct TclPlatStubs	*new_TclPlatStubs(void)
{
	struct TclPlatStubs	*new;

	if (!(new = (struct TclPlatStubs*)malloc(sizeof(struct TclPlatStubs))))
		return (NULL);
	new->magic = 0;
	new->hooks = NULL;
	new->tcl_WinUtfToTChar = NULL;
	new->tcl_WinTCharToUtf = NULL;
	new->tcl_MacOSXOpenBundleResources = NULL;
	new->tcl_MacOSXOpenVersionedBundleResources = NULL;
	return (new);
}

struct TclPlatStubs	*manage_TclPlatStubs(int macro)
{
	static struct TclPlatStubs	*current;

	if (macro == NEW)
		current = new_TclPlatStubs();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_TclPlatStubs: no decent macro\n", 37);
	return (NULL);
}
