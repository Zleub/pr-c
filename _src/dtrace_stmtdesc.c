#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_stmtdesc	*new_dtrace_stmtdesc(void)
{
	struct dtrace_stmtdesc	*new;

	if (!(new = (struct dtrace_stmtdesc*)malloc(sizeof(struct dtrace_stmtdesc))))
		return (NULL);
	new->dtsd_ecbdesc = NULL;
	new->dtsd_action = NULL;
	new->dtsd_action_last = NULL;
	new->dtsd_aggdata = NULL;
	new->dtsd_fmtdata = NULL;
	new->dtsd_callback)() = NULL;
	new->dtsd_data = NULL;
	new->dtsd_descattr = 0;
	new->dtsd_stmtattr = 0;
	return (new);
}

struct dtrace_stmtdesc	*manage_dtrace_stmtdesc(int macro)
{
	static struct dtrace_stmtdesc	*current;

	if (macro == NEW)
		current = new_dtrace_stmtdesc();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_stmtdesc: no decent macro\n", 40);
	return (NULL);
}
