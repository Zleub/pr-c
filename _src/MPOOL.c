#include <stdlib.h>
#include <string.h>
#include <mpool.h>

enum e_macro
{
	NEW,
	GET
};

struct MPOOL	*new_MPOOL(void)
{
	struct MPOOL	*new;

	if (!(new = (struct MPOOL*)malloc(sizeof(struct MPOOL))))
		return (NULL);
	new->curcache = 0;
	new->maxcache = 0;
	new->npages = 0;
	new->pagesize = 0;
	new->fd = 0;
	new->pgin = NULL;
	new->pgout = NULL;
	new->pgcookie = NULL;
	new->cachehit = 0;
	new->cachemiss = 0;
	new->pagealloc = 0;
	new->pageflush = 0;
	new->pageget = 0;
	new->pagenew = 0;
	new->pageput = 0;
	new->pageread = 0;
	new->pagewrite = 0;
	return (new);
}

struct MPOOL	*manage_MPOOL(int macro)
{
	static struct MPOOL	*current;

	if (macro == NEW)
		current = new_MPOOL();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_MPOOL: no decent macro\n", 30);
	return (NULL);
}
