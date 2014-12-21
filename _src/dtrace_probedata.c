#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_probedata	*new_dtrace_probedata(void)
{
	struct dtrace_probedata	*new;

	if (!(new = (struct dtrace_probedata*)malloc(sizeof(struct dtrace_probedata))))
		return (NULL);
	new->dtpda_handle = NULL;
	new->dtpda_edesc = NULL;
	new->dtpda_pdesc = NULL;
	new->dtpda_cpu = 0;
	new->dtpda_data = 0;
	new->dtpda_flow = 0;
	new->dtpda_prefix = NULL;
	new->dtpda_indent = 0;
	return (new);
}

struct dtrace_probedata	*manage_dtrace_probedata(int macro)
{
	static struct dtrace_probedata	*current;

	if (macro == NEW)
		current = new_dtrace_probedata();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_probedata: no decent macro\n", 41);
	return (NULL);
}
