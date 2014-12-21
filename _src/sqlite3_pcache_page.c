#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_pcache_page	*new_sqlite3_pcache_page(void)
{
	struct sqlite3_pcache_page	*new;

	if (!(new = (struct sqlite3_pcache_page*)malloc(sizeof(struct sqlite3_pcache_page))))
		return (NULL);
	new->pBuf = NULL;
	new->pExtra = NULL;
	return (new);
}

struct sqlite3_pcache_page	*manage_sqlite3_pcache_page(int macro)
{
	static struct sqlite3_pcache_page	*current;

	if (macro == NEW)
		current = new_sqlite3_pcache_page();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_pcache_page: no decent macro\n", 44);
	return (NULL);
}
