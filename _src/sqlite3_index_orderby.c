#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_index_orderby	*new_sqlite3_index_orderby(void)
{
	struct sqlite3_index_orderby	*new;

	if (!(new = (struct sqlite3_index_orderby*)malloc(sizeof(struct sqlite3_index_orderby))))
		return (NULL);
	new->iColumn = 0;
	new->desc = 0;
	return (new);
}

struct sqlite3_index_orderby	*manage_sqlite3_index_orderby(int macro)
{
	static struct sqlite3_index_orderby	*current;

	if (macro == NEW)
		current = new_sqlite3_index_orderby();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_index_orderby: no decent macro\n", 46);
	return (NULL);
}
