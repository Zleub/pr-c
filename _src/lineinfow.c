#include <stdlib.h>
#include <string.h>
#include <histedit.h>

enum e_macro
{
	NEW,
	GET
};

struct lineinfow	*new_lineinfow(void)
{
	struct lineinfow	*new;

	if (!(new = (struct lineinfow*)malloc(sizeof(struct lineinfow))))
		return (NULL);
	new->buffer = NULL;
	new->cursor = NULL;
	new->lastchar = NULL;
	return (new);
}

struct lineinfow	*manage_lineinfow(int macro)
{
	static struct lineinfow	*current;

	if (macro == NEW)
		current = new_lineinfow();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_lineinfow: no decent macro\n", 34);
	return (NULL);
}
