#include <stdlib.h>
#include <string.h>
#include <grp.h>

enum e_macro
{
	NEW,
	GET
};

struct group	*new_group(void)
{
	struct group	*new;

	if (!(new = (struct group*)malloc(sizeof(struct group))))
		return (NULL);
	new->gr_name = NULL;
	new->gr_passwd = NULL;
	new->gr_gid = 0;
	new->*gr_mem = NULL;
	return (new);
}

struct group	*manage_group(int macro)
{
	static struct group	*current;

	if (macro == NEW)
		current = new_group();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_group: no decent macro\n", 30);
	return (NULL);
}
