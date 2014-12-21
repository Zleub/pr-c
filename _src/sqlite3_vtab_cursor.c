#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_vtab_cursor	*new_sqlite3_vtab_cursor(void)
{
	struct sqlite3_vtab_cursor	*new;

	if (!(new = (struct sqlite3_vtab_cursor*)malloc(sizeof(struct sqlite3_vtab_cursor))))
		return (NULL);
	new->pVtab = NULL;
	return (new);
}

struct sqlite3_vtab_cursor	*manage_sqlite3_vtab_cursor(int macro)
{
	static struct sqlite3_vtab_cursor	*current;

	if (macro == NEW)
		current = new_sqlite3_vtab_cursor();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_vtab_cursor: no decent macro\n", 44);
	return (NULL);
}
