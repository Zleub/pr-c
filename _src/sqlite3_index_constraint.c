#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_index_constraint	*new_sqlite3_index_constraint(void)
{
	struct sqlite3_index_constraint	*new;

	if (!(new = (struct sqlite3_index_constraint*)malloc(sizeof(struct sqlite3_index_constraint))))
		return (NULL);
	new->iColumn = 0;
	new->op = 0;
	new->usable = 0;
	new->iTermOffset = 0;
	return (new);
}

struct sqlite3_index_constraint	*manage_sqlite3_index_constraint(int macro)
{
	static struct sqlite3_index_constraint	*current;

	if (macro == NEW)
		current = new_sqlite3_index_constraint();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_index_constraint: no decent macro\n", 49);
	return (NULL);
}
