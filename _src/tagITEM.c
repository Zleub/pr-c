#include <stdlib.h>
#include <string.h>
#include <menu.h>

enum e_macro
{
	NEW,
	GET
};

struct tagITEM	*new_tagITEM(void)
{
	struct tagITEM	*new;

	if (!(new = (struct tagITEM*)malloc(sizeof(struct tagITEM))))
		return (NULL);
	new->name = 0;
	new->description = 0;
	new->imenu = NULL;
	new->userptr = NULL;
	new->opt = 0;
	new->index = 0;
	new->y = 0;
	new->x = 0;
	new->value = 0;
	new->left = NULL;
	new->right = NULL;
	new->up = NULL;
	new->down = NULL;
	return (new);
}

struct tagITEM	*manage_tagITEM(int macro)
{
	static struct tagITEM	*current;

	if (macro == NEW)
		current = new_tagITEM();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_tagITEM: no decent macro\n", 32);
	return (NULL);
}
