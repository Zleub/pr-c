#include <stdlib.h>
#include <string.h>
#include <tclDecls.h>

enum e_macro
{
	NEW,
	GET
};

struct TclStubHooks	*new_TclStubHooks(void)
{
	struct TclStubHooks	*new;

	if (!(new = (struct TclStubHooks*)malloc(sizeof(struct TclStubHooks))))
		return (NULL);
	new->tclPlatStubs = NULL;
	new->tclIntStubs = NULL;
	new->tclIntPlatStubs = NULL;
	return (new);
}

struct TclStubHooks	*manage_TclStubHooks(int macro)
{
	static struct TclStubHooks	*current;

	if (macro == NEW)
		current = new_TclStubHooks();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_TclStubHooks: no decent macro\n", 37);
	return (NULL);
}
