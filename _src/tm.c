#include <stdlib.h>
#include <string.h>
#include <time.h>

enum e_macro
{
	NEW,
	GET
};

struct tm	*new_tm(void)
{
	struct tm	*new;

	if (!(new = (struct tm*)malloc(sizeof(struct tm))))
		return (NULL);
	new->tm_sec = 0;
	new->tm_min = 0;
	new->tm_hour = 0;
	new->tm_mday = 0;
	new->tm_mon = 0;
	new->tm_year = 0;
	new->tm_wday = 0;
	new->tm_yday = 0;
	new->tm_isdst = 0;
	new->tm_gmtoff = 0;
	new->tm_zone = NULL;
	return (new);
}

struct tm	*manage_tm(int macro)
{
	static struct tm	*current;

	if (macro == NEW)
		current = new_tm();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_tm: no decent macro\n", 27);
	return (NULL);
}
