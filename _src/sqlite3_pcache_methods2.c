#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_pcache_methods2	*new_sqlite3_pcache_methods2(void)
{
	struct sqlite3_pcache_methods2	*new;

	if (!(new = (struct sqlite3_pcache_methods2*)malloc(sizeof(struct sqlite3_pcache_methods2))))
		return (NULL);
	new->iVersion = 0;
	new->pArg = NULL;
	new->xInit = NULL;
	new->xShutdown = NULL;
	new->xCreate = NULL;
	new->xCachesize = NULL;
	new->xPagecount = NULL;
	new->xFetch = NULL;
	new->xUnpin = NULL;
	new->oldKey, unsigned newKey) = 0;
	new->xTruncate = NULL;
	new->xDestroy = NULL;
	new->xShrink = NULL;
	return (new);
}

struct sqlite3_pcache_methods2	*manage_sqlite3_pcache_methods2(int macro)
{
	static struct sqlite3_pcache_methods2	*current;

	if (macro == NEW)
		current = new_sqlite3_pcache_methods2();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_pcache_methods2: no decent macro\n", 48);
	return (NULL);
}
