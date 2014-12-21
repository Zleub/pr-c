#include <stdlib.h>
#include <string.h>
#include <db.h>

enum e_macro
{
	NEW,
	GET
};

struct __db	*new___db(void)
{
	struct __db	*new;

	if (!(new = (struct __db*)malloc(sizeof(struct __db))))
		return (NULL);
	new->type = 0;
	new->close = NULL;
	new->del = NULL;
	new->get = NULL;
	new->put = NULL;
	new->seq = NULL;
	new->sync = NULL;
	new->internal = NULL;
	new->fd = NULL;
	return (new);
}

struct __db	*manage___db(int macro)
{
	static struct __db	*current;

	if (macro == NEW)
		current = new___db();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage___db: no decent macro\n", 29);
	return (NULL);
}
