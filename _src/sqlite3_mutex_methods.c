#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_mutex_methods	*new_sqlite3_mutex_methods(void)
{
	struct sqlite3_mutex_methods	*new;

	if (!(new = (struct sqlite3_mutex_methods*)malloc(sizeof(struct sqlite3_mutex_methods))))
		return (NULL);
	new->xMutexInit = NULL;
	new->xMutexEnd = NULL;
	new->xMutexAlloc = NULL;
	new->xMutexFree = NULL;
	new->xMutexEnter = NULL;
	new->xMutexTry = NULL;
	new->xMutexLeave = NULL;
	new->xMutexHeld = NULL;
	new->xMutexNotheld = NULL;
	return (new);
}

struct sqlite3_mutex_methods	*manage_sqlite3_mutex_methods(int macro)
{
	static struct sqlite3_mutex_methods	*current;

	if (macro == NEW)
		current = new_sqlite3_mutex_methods();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_mutex_methods: no decent macro\n", 46);
	return (NULL);
}
