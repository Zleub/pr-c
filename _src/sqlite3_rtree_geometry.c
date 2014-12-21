#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_rtree_geometry	*new_sqlite3_rtree_geometry(void)
{
	struct sqlite3_rtree_geometry	*new;

	if (!(new = (struct sqlite3_rtree_geometry*)malloc(sizeof(struct sqlite3_rtree_geometry))))
		return (NULL);
	new->pContext = NULL;
	new->nParam = 0;
	new->aParam = NULL;
	new->pUser = NULL;
	new->xDelUser = NULL;
	return (new);
}

struct sqlite3_rtree_geometry	*manage_sqlite3_rtree_geometry(int macro)
{
	static struct sqlite3_rtree_geometry	*current;

	if (macro == NEW)
		current = new_sqlite3_rtree_geometry();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sqlite3_rtree_geometry: no decent macro\n", 47);
	return (NULL);
}
