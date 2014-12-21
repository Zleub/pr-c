#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_dropdata	*new_dtrace_dropdata(void)
{
	struct dtrace_dropdata	*new;

	if (!(new = (struct dtrace_dropdata*)malloc(sizeof(struct dtrace_dropdata))))
		return (NULL);
	new->dtdda_handle = NULL;
	new->dtdda_cpu = 0;
	new->dtdda_kind = 0;
	new->dtdda_drops = 0;
	new->dtdda_total = 0;
	new->dtdda_msg = NULL;
	return (new);
}

struct dtrace_dropdata	*manage_dtrace_dropdata(int macro)
{
	static struct dtrace_dropdata	*current;

	if (macro == NEW)
		current = new_dtrace_dropdata();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_dropdata: no decent macro\n", 40);
	return (NULL);
}
