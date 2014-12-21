#include <stdlib.h>
#include <string.h>
#include <form.h>

enum e_macro
{
	NEW,
	GET
};

struct formnode	*new_formnode(void)
{
	struct formnode	*new;

	if (!(new = (struct formnode*)malloc(sizeof(struct formnode))))
		return (NULL);
	new->status = 0;
	new->rows = 0;
	new->cols = 0;
	new->currow = 0;
	new->curcol = 0;
	new->toprow = 0;
	new->begincol = 0;
	new->maxfield = 0;
	new->maxpage = 0;
	new->curpage = 0;
	new->opts = 0;
	new->		win = NULL;
	new->		sub = NULL;
	new->		w = NULL;
	new->*		field = NULL;
	new->		current = NULL;
	new->		page = NULL;
	new->		usrptr = NULL;
	new->forminit = NULL;
	new->formterm = NULL;
	new->fieldinit = NULL;
	new->fieldterm = NULL;
	return (new);
}

struct formnode	*manage_formnode(int macro)
{
	static struct formnode	*current;

	if (macro == NEW)
		current = new_formnode();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_formnode: no decent macro\n", 33);
	return (NULL);
}
