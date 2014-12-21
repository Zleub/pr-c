#include <stdlib.h>
#include <string.h>
#include <tkDecls.h>

enum e_macro
{
	NEW,
	GET
};

struct TkStubHooks	*new_TkStubHooks(void)
{
	struct TkStubHooks	*new;

	if (!(new = (struct TkStubHooks*)malloc(sizeof(struct TkStubHooks))))
		return (NULL);
	new->tkPlatStubs = NULL;
	new->tkIntStubs = NULL;
	new->tkIntPlatStubs = NULL;
	new->tkIntXlibStubs = NULL;
	return (new);
}

struct TkStubHooks	*manage_TkStubHooks(int macro)
{
	static struct TkStubHooks	*current;

	if (macro == NEW)
		current = new_TkStubHooks();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_TkStubHooks: no decent macro\n", 36);
	return (NULL);
}
