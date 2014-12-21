#include <stdlib.h>
#include <string.h>
#include <utmp.h>

enum e_macro
{
	NEW,
	GET
};

struct utmp	*new_utmp(void)
{
	struct utmp	*new;

	if (!(new = (struct utmp*)malloc(sizeof(struct utmp))))
		return (NULL);
	bzero((void*)(&new->ut_line), sizeof(char) * UT_LINESIZE);
	bzero((void*)(&new->ut_name), sizeof(char) * UT_NAMESIZE);
	bzero((void*)(&new->ut_host), sizeof(char) * UT_HOSTSIZE);
	new->ut_time = 0;
	return (new);
}

struct utmp	*manage_utmp(int macro)
{
	static struct utmp	*current;

	if (macro == NEW)
		current = new_utmp();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_utmp: no decent macro\n", 29);
	return (NULL);
}
