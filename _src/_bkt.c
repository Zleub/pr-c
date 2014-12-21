#include <stdlib.h>
#include <string.h>
#include <mpool.h>

enum e_macro
{
	NEW,
	GET
};

struct _bkt	*new__bkt(void)
{
	struct _bkt	*new;

	if (!(new = (struct _bkt*)malloc(sizeof(struct _bkt))))
		return (NULL);
	new->page = NULL;
	new->pgno = 0;
	new->flags = 0;
	return (new);
}

struct _bkt	*manage__bkt(int macro)
{
	static struct _bkt	*current;

	if (macro == NEW)
		current = new__bkt();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__bkt: no decent macro\n", 29);
	return (NULL);
}
