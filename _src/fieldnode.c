#include <stdlib.h>
#include <string.h>
#include <form.h>

enum e_macro
{
	NEW,
	GET
};

struct fieldnode	*new_fieldnode(void)
{
	struct fieldnode	*new;

	if (!(new = (struct fieldnode*)malloc(sizeof(struct fieldnode))))
		return (NULL);
	new->status = 0;
	new->rows = 0;
	new->cols = 0;
	new->frow = 0;
	new->fcol = 0;
	new->drows = 0;
	new->dcols = 0;
	new->maxgrow = 0;
	new->nrow = 0;
	new->nbuf = 0;
	new->just = 0;
	new->page = 0;
	new->index = 0;
	new->pad = 0;
	new->fore = 0;
	new->back = 0;
	new->opts = 0;
	new->	snext = NULL;
	new->	sprev = NULL;
	new->	link = NULL;
	new->	form = NULL;
	new->	type = NULL;
	new->		arg = NULL;
	new->		buf = NULL;
	new->		usrptr = NULL;
	return (new);
}

struct fieldnode	*manage_fieldnode(int macro)
{
	static struct fieldnode	*current;

	if (macro == NEW)
		current = new_fieldnode();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_fieldnode: no decent macro\n", 34);
	return (NULL);
}
