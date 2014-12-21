#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_proginfo	*new_dtrace_proginfo(void)
{
	struct dtrace_proginfo	*new;

	if (!(new = (struct dtrace_proginfo*)malloc(sizeof(struct dtrace_proginfo))))
		return (NULL);
	new->dpi_descattr = 0;
	new->dpi_stmtattr = 0;
	new->dpi_aggregates = 0;
	new->dpi_recgens = 0;
	new->dpi_matches = 0;
	new->dpi_speculations = 0;
	return (new);
}

struct dtrace_proginfo	*manage_dtrace_proginfo(int macro)
{
	static struct dtrace_proginfo	*current;

	if (macro == NEW)
		current = new_dtrace_proginfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_proginfo: no decent macro\n", 40);
	return (NULL);
}
