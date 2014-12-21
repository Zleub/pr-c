#include <stdlib.h>
#include <string.h>
#include <printerdb.h>

enum e_macro
{
	NEW,
	GET
};

struct prdb_property	*new_prdb_property(void)
{
	struct prdb_property	*new;

	if (!(new = (struct prdb_property*)malloc(sizeof(struct prdb_property))))
		return (NULL);
	new->pp_key = NULL;
	new->pp_value = NULL;
	return (new);
}

struct prdb_property	*manage_prdb_property(int macro)
{
	static struct prdb_property	*current;

	if (macro == NEW)
		current = new_prdb_property();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_prdb_property: no decent macro\n", 38);
	return (NULL);
}
