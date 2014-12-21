#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_mem_methods	*new_sqlite3_mem_methods(void)
{
	struct sqlite3_mem_methods	*new;

	if (!(new = (struct sqlite3_mem_methods*)malloc(sizeof(struct sqlite3_mem_methods))))
		return (NULL);
	new->xMalloc = NULL;
	new->xFree = NULL;
	new->xRealloc = NULL;
	new->xSize = NULL;
	new->xRoundup = NULL;
	new->xInit = NULL;
	new->xShutdown = NULL;
	new->pAppData = NULL;
	return (new);
}

struct sqlite3_mem_methods	*manage_sqlite3_mem_methods(int macro)
{
	static struct sqlite3_mem_methods	*current;

	if (macro == NEW)
		current = new_sqlite3_mem_methods();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_mem_methods: no decent macro\n", 44);
	return (NULL);
}
