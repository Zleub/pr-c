#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_module	*new_sqlite3_module(void)
{
	struct sqlite3_module	*new;

	if (!(new = (struct sqlite3_module*)malloc(sizeof(struct sqlite3_module))))
		return (NULL);
	new->iVersion = 0;
	new->*ppVTab, char**) = NULL;
	new->*ppVTab, char**) = NULL;
	new->xBestIndex = NULL;
	new->xDisconnect = NULL;
	new->xDestroy = NULL;
	new->xOpen = NULL;
	new->xClose = NULL;
	new->*argv) = NULL;
	new->xNext = NULL;
	new->xEof = NULL;
	new->xColumn = NULL;
	new->xRowid = NULL;
	new->xUpdate = NULL;
	new->xBegin = NULL;
	new->xSync = NULL;
	new->xCommit = NULL;
	new->xRollback = NULL;
	new->*ppArg) = NULL;
	new->xRename = NULL;
	new->xSavepoint = NULL;
	new->xRelease = NULL;
	new->xRollbackTo = NULL;
	return (new);
}

struct sqlite3_module	*manage_sqlite3_module(int macro)
{
	static struct sqlite3_module	*current;

	if (macro == NEW)
		current = new_sqlite3_module();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_module: no decent macro\n", 39);
	return (NULL);
}
