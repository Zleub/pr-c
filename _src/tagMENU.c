#include <stdlib.h>
#include <string.h>
#include <menu.h>

enum e_macro
{
	NEW,
	GET
};

struct tagMENU	*new_tagMENU(void)
{
	struct tagMENU	*new;

	if (!(new = (struct tagMENU*)malloc(sizeof(struct tagMENU))))
		return (NULL);
	new->height = 0;
	new->width = 0;
	new->rows = 0;
	new->cols = 0;
	new->frows = 0;
	new->fcols = 0;
	new->arows = 0;
	new->namelen = 0;
	new->desclen = 0;
	new->marklen = 0;
	new->itemlen = 0;
	new->spc_desc = 0;
	new->spc_cols = 0;
	new->spc_rows = 0;
	new->pattern = NULL;
	new->pindex = 0;
	new->win = NULL;
	new->sub = NULL;
	new->userwin = NULL;
	new->usersub = NULL;
	new->*items = NULL;
	new->nitems = 0;
	new->curitem = NULL;
	new->toprow = 0;
	new->fore = 0;
	new->back = 0;
	new->grey = 0;
	new->pad = 0;
	new->menuinit = 0;
	new->menuterm = 0;
	new->iteminit = 0;
	new->itemterm = 0;
	new->userptr = NULL;
	new->mark = NULL;
	new->opt = 0;
	new->status = 0;
	return (new);
}

struct tagMENU	*manage_tagMENU(int macro)
{
	static struct tagMENU	*current;

	if (macro == NEW)
		current = new_tagMENU();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_tagMENU: no decent macro\n", 32);
	return (NULL);
}
