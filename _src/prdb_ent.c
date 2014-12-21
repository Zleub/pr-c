#include <stdlib.h>
#include <string.h>
#include <printerdb.h>

enum e_macro
{
	NEW,
	GET
};

struct prdb_ent	*new_prdb_ent(void)
{
	struct prdb_ent	*new;

	if (!(new = (struct prdb_ent*)malloc(sizeof(struct prdb_ent))))
		return (NULL);
	new->*pe_name = NULL;
	new->pe_nprops = 0;
	new->pe_prop = NULL;
	return (new);
}

struct prdb_ent	*manage_prdb_ent(int macro)
{
	static struct prdb_ent	*current;

	if (macro == NEW)
		current = new_prdb_ent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_prdb_ent: no decent macro\n", 33);
	return (NULL);
}
