#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_vtab	*new_sqlite3_vtab(void)
{
	struct sqlite3_vtab	*new;

	if (!(new = (struct sqlite3_vtab*)malloc(sizeof(struct sqlite3_vtab))))
		return (NULL);
	new->pModule = NULL;
	new->nRef = 0;
	new->zErrMsg = NULL;
	return (new);
}

struct sqlite3_vtab	*manage_sqlite3_vtab(int macro)
{
	static struct sqlite3_vtab	*current;

	if (macro == NEW)
		current = new_sqlite3_vtab();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_vtab: no decent macro\n", 37);
	return (NULL);
}
