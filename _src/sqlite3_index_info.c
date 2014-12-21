#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_index_info	*new_sqlite3_index_info(void)
{
	struct sqlite3_index_info	*new;

	if (!(new = (struct sqlite3_index_info*)malloc(sizeof(struct sqlite3_index_info))))
		return (NULL);
	new->nConstraint = 0;
	new->iColumn = 0;
	new->op = 0;
	new->usable = 0;
	new->iTermOffset = 0;
	return (new);
}

struct sqlite3_index_info	*manage_sqlite3_index_info(int macro)
{
	static struct sqlite3_index_info	*current;

	if (macro == NEW)
		current = new_sqlite3_index_info();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_index_info: no decent macro\n", 43);
	return (NULL);
}
