#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_file	*new_sqlite3_file(void)
{
	struct sqlite3_file	*new;

	if (!(new = (struct sqlite3_file*)malloc(sizeof(struct sqlite3_file))))
		return (NULL);
	new->pMethods = NULL;
	return (new);
}

struct sqlite3_file	*manage_sqlite3_file(int macro)
{
	static struct sqlite3_file	*current;

	if (macro == NEW)
		current = new_sqlite3_file();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_file: no decent macro\n", 37);
	return (NULL);
}
