#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_syminfo	*new_dtrace_syminfo(void)
{
	struct dtrace_syminfo	*new;

	if (!(new = (struct dtrace_syminfo*)malloc(sizeof(struct dtrace_syminfo))))
		return (NULL);
	new->dts_object = NULL;
	new->dts_name = NULL;
	new->dts_id = 0;
	return (new);
}

struct dtrace_syminfo	*manage_dtrace_syminfo(int macro)
{
	static struct dtrace_syminfo	*current;

	if (macro == NEW)
		current = new_dtrace_syminfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_syminfo: no decent macro\n", 39);
	return (NULL);
}
