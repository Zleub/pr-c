#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_errdata	*new_dtrace_errdata(void)
{
	struct dtrace_errdata	*new;

	if (!(new = (struct dtrace_errdata*)malloc(sizeof(struct dtrace_errdata))))
		return (NULL);
	new->dteda_handle = NULL;
	new->dteda_edesc = NULL;
	new->dteda_pdesc = NULL;
	new->dteda_cpu = 0;
	new->dteda_action = 0;
	new->dteda_offset = 0;
	new->dteda_fault = 0;
	new->dteda_addr = 0;
	new->dteda_msg = NULL;
	return (new);
}

struct dtrace_errdata	*manage_dtrace_errdata(int macro)
{
	static struct dtrace_errdata	*current;

	if (macro == NEW)
		current = new_dtrace_errdata();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_errdata: no decent macro\n", 39);
	return (NULL);
}
