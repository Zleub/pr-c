#include <stdlib.h>
#include <string.h>
#include <form.h>

enum e_macro
{
	NEW,
	GET
};

struct typenode	*new_typenode(void)
{
	struct typenode	*new;

	if (!(new = (struct typenode*)malloc(sizeof(struct typenode))))
		return (NULL);
	new->status = 0;
	new->ref = 0;
	new->	left = NULL;
	new->	right = NULL;
	new->makearg = NULL;
	new->copyarg = NULL;
	new->freearg = NULL;
	new->fcheck = NULL;
	new->ccheck = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

struct typenode	*manage_typenode(int macro)
{
	static struct typenode	*current;

	if (macro == NEW)
		current = new_typenode();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_typenode: no decent macro\n", 33);
	return (NULL);
}
