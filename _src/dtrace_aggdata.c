#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_aggdata	*new_dtrace_aggdata(void)
{
	struct dtrace_aggdata	*new;

	if (!(new = (struct dtrace_aggdata*)malloc(sizeof(struct dtrace_aggdata))))
		return (NULL);
	new->dtada_handle = NULL;
	new->dtada_desc = NULL;
	new->dtada_edesc = NULL;
	new->dtada_pdesc = NULL;
	new->dtada_data = 0;
	new->dtada_normal = 0;
	new->dtada_size = 0;
	new->dtada_delta = 0;
	new->dtada_percpu = NULL;
	new->dtada_percpu_delta = NULL;
	return (new);
}

struct dtrace_aggdata	*manage_dtrace_aggdata(int macro)
{
	static struct dtrace_aggdata	*current;

	if (macro == NEW)
		current = new_dtrace_aggdata();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_aggdata: no decent macro\n", 39);
	return (NULL);
}
