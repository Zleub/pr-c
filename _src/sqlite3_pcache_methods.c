#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_pcache_methods	*new_sqlite3_pcache_methods(void)
{
	struct sqlite3_pcache_methods	*new;

	if (!(new = (struct sqlite3_pcache_methods*)malloc(sizeof(struct sqlite3_pcache_methods))))
		return (NULL);
	new->pArg = NULL;
	new->xInit = NULL;
	new->xShutdown = NULL;
	new->xCreate = NULL;
	new->xCachesize = NULL;
	new->xPagecount = NULL;
	new->xFetch = NULL;
	new->xUnpin = NULL;
	new->xRekey = NULL;
	new->xTruncate = NULL;
	new->xDestroy = NULL;
	return (new);
}

struct sqlite3_pcache_methods	*manage_sqlite3_pcache_methods(int macro)
{
	static struct sqlite3_pcache_methods	*current;

	if (macro == NEW)
		current = new_sqlite3_pcache_methods();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_pcache_methods: no decent macro\n", 47);
	return (NULL);
}
