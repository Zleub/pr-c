#include <stdlib.h>
#include <string.h>
#include <utmp.h>

enum e_macro
{
	NEW,
	GET
};

struct lastlog	*new_lastlog(void)
{
	struct lastlog	*new;

	if (!(new = (struct lastlog*)malloc(sizeof(struct lastlog))))
		return (NULL);
	new->ll_time = 0;
	bzero((void*)(&new->ll_line), sizeof(char) * UT_LINESIZE);
	bzero((void*)(&new->ll_host), sizeof(char) * UT_HOSTSIZE);
	return (new);
}

struct lastlog	*manage_lastlog(int macro)
{
	static struct lastlog	*current;

	if (macro == NEW)
		current = new_lastlog();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_lastlog: no decent macro\n", 32);
	return (NULL);
}
