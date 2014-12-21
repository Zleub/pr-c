#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_typeinfo	*new_dtrace_typeinfo(void)
{
	struct dtrace_typeinfo	*new;

	if (!(new = (struct dtrace_typeinfo*)malloc(sizeof(struct dtrace_typeinfo))))
		return (NULL);
	new->dtt_object = NULL;
	new->dtt_ctfp = NULL;
	new->dtt_type = 0;
	return (new);
}

struct dtrace_typeinfo	*manage_dtrace_typeinfo(int macro)
{
	static struct dtrace_typeinfo	*current;

	if (macro == NEW)
		current = new_dtrace_typeinfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_typeinfo: no decent macro\n", 40);
	return (NULL);
}
