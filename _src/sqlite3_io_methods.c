#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_io_methods	*new_sqlite3_io_methods(void)
{
	struct sqlite3_io_methods	*new;

	if (!(new = (struct sqlite3_io_methods*)malloc(sizeof(struct sqlite3_io_methods))))
		return (NULL);
	new->iVersion = 0;
	new->xClose = NULL;
	new->xRead = NULL;
	new->xWrite = NULL;
	new->xTruncate = NULL;
	new->xSync = NULL;
	new->xFileSize = NULL;
	new->xLock = NULL;
	new->xUnlock = NULL;
	new->xCheckReservedLock = NULL;
	new->xFileControl = NULL;
	new->xSectorSize = NULL;
	new->xDeviceCharacteristics = NULL;
	new->xShmMap = NULL;
	new->xShmLock = NULL;
	new->xShmBarrier = NULL;
	new->xShmUnmap = NULL;
	return (new);
}

struct sqlite3_io_methods	*manage_sqlite3_io_methods(int macro)
{
	static struct sqlite3_io_methods	*current;

	if (macro == NEW)
		current = new_sqlite3_io_methods();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_io_methods: no decent macro\n", 43);
	return (NULL);
}
