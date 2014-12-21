#include <stdlib.h>
#include <string.h>
#include <search.h>

enum e_macro
{
	NEW,
	GET
};

struct node	*new_node(void)
{
	struct node	*new;

	if (!(new = (struct node*)malloc(sizeof(struct node))))
		return (NULL);
	new->key = NULL;
	new->llink, *rlink = NULL;
	return (new);
}

struct node	*manage_node(int macro)
{
	static struct node	*current;

	if (macro == NEW)
		current = new_node();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_node: no decent macro\n", 29);
	return (NULL);
}
