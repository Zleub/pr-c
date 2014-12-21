#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_vfs	*new_sqlite3_vfs(void)
{
	struct sqlite3_vfs	*new;

	if (!(new = (struct sqlite3_vfs*)malloc(sizeof(struct sqlite3_vfs))))
		return (NULL);
	new->iVersion = 0;
	new->szOsFile = 0;
	new->mxPathname = 0;
	new->pNext = NULL;
	new->zName = NULL;
	new->pAppData = NULL;
	new->pOutFlags) = NULL;
	new->xDelete = NULL;
	new->xAccess = NULL;
	new->xFullPathname = NULL;
	new->xDlOpen = NULL;
	new->xDlError = NULL;
	new->xDlSym = NULL;
	new->xDlClose = NULL;
	new->xRandomness = NULL;
	new->xSleep = NULL;
	new->xCurrentTime = NULL;
	new->xGetLastError = NULL;
	new->xCurrentTimeInt64 = NULL;
	new->xSetSystemCall = NULL;
	new->xGetSystemCall = NULL;
	new->xNextSystemCall = NULL;
	return (new);
}

struct sqlite3_vfs	*manage_sqlite3_vfs(int macro)
{
	static struct sqlite3_vfs	*current;

	if (macro == NEW)
		current = new_sqlite3_vfs();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_vfs: no decent macro\n", 36);
	return (NULL);
}
