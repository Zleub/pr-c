#include <stdlib.h>
#include <string.h>
#include <aliasdb.h>

enum e_macro
{
	NEW,
	GET
};

struct aliasent	*new_aliasent(void)
{
	struct aliasent	*new;

	if (!(new = (struct aliasent*)malloc(sizeof(struct aliasent))))
		return (NULL);
	new->alias_name = NULL;
	new->alias_members_len = 0;
	new->*alias_members = NULL;
	new->alias_local = 0;
	return (new);
}

struct aliasent	*manage_aliasent(int macro)
{
	static struct aliasent	*current;

	if (macro == NEW)
		current = new_aliasent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_aliasent: no decent macro\n", 33);
	return (NULL);
}
