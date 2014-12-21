#include <stdlib.h>
#include <string.h>
#include <utime.h>

enum e_macro
{
	NEW,
	GET
};

struct utimbuf	*new_utimbuf(void)
{
	struct utimbuf	*new;

	if (!(new = (struct utimbuf*)malloc(sizeof(struct utimbuf))))
		return (NULL);
	new->actime = 0;
	new->modtime = 0;
	return (new);
}

struct utimbuf	*manage_utimbuf(int macro)
{
	static struct utimbuf	*current;

	if (macro == NEW)
		current = new_utimbuf();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_utimbuf: no decent macro\n", 32);
	return (NULL);
}
