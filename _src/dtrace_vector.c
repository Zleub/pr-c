#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_vector	*new_dtrace_vector(void)
{
	struct dtrace_vector	*new;

	if (!(new = (struct dtrace_vector*)malloc(sizeof(struct dtrace_vector))))
		return (NULL);
	new->dtv_ioctl = NULL;
	new->) = NULL;
	new->dtv_status = NULL;
	new->dtv_sysconf = NULL;
	return (new);
}

struct dtrace_vector	*manage_dtrace_vector(int macro)
{
	static struct dtrace_vector	*current;

	if (macro == NEW)
		current = new_dtrace_vector();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_vector: no decent macro\n", 38);
	return (NULL);
}
