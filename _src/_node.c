#include <stdlib.h>
#include <string.h>
#include <strhash.h>

enum e_macro
{
	NEW,
	GET
};

struct _node	*new__node(void)
{
	struct _node	*new;

	if (!(new = (struct _node*)malloc(sizeof(struct _node))))
		return (NULL);
	new->key = NULL;
	new->data = NULL;
	new->next = NULL;
	return (new);
}

struct _node	*manage__node(int macro)
{
	static struct _node	*current;

	if (macro == NEW)
		current = new__node();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__node: no decent macro\n", 30);
	return (NULL);
}
