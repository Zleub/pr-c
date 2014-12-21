#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_setoptdata	*new_dtrace_setoptdata(void)
{
	struct dtrace_setoptdata	*new;

	if (!(new = (struct dtrace_setoptdata*)malloc(sizeof(struct dtrace_setoptdata))))
		return (NULL);
	new->dtsda_handle = NULL;
	new->dtsda_probe = NULL;
	new->dtsda_option = NULL;
	new->dtsda_oldval = 0;
	new->dtsda_newval = 0;
	return (new);
}

struct dtrace_setoptdata	*manage_dtrace_setoptdata(int macro)
{
	static struct dtrace_setoptdata	*current;

	if (macro == NEW)
		current = new_dtrace_setoptdata();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_setoptdata: no decent macro\n", 42);
	return (NULL);
}
