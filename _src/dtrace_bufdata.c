#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_bufdata	*new_dtrace_bufdata(void)
{
	struct dtrace_bufdata	*new;

	if (!(new = (struct dtrace_bufdata*)malloc(sizeof(struct dtrace_bufdata))))
		return (NULL);
	new->dtbda_handle = NULL;
	new->dtbda_buffered = NULL;
	new->dtbda_probe = NULL;
	new->dtbda_recdesc = NULL;
	new->dtbda_aggdata = NULL;
	new->dtbda_flags = 0;
	return (new);
}

struct dtrace_bufdata	*manage_dtrace_bufdata(int macro)
{
	static struct dtrace_bufdata	*current;

	if (macro == NEW)
		current = new_dtrace_bufdata();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_bufdata: no decent macro\n", 39);
	return (NULL);
}
