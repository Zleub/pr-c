#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_probeinfo	*new_dtrace_probeinfo(void)
{
	struct dtrace_probeinfo	*new;

	if (!(new = (struct dtrace_probeinfo*)malloc(sizeof(struct dtrace_probeinfo))))
		return (NULL);
	new->dtp_attr = 0;
	new->dtp_arga = 0;
	new->dtp_argv = NULL;
	new->dtp_argc = 0;
	return (new);
}

struct dtrace_probeinfo	*manage_dtrace_probeinfo(int macro)
{
	static struct dtrace_probeinfo	*current;

	if (macro == NEW)
		current = new_dtrace_probeinfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_probeinfo: no decent macro\n", 41);
	return (NULL);
}
