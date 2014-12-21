#include <stdlib.h>
#include <string.h>
#include <term_entry.h>

enum e_macro
{
	NEW,
	GET
};

struct entry	*new_entry(void)
{
	struct entry	*new;

	if (!(new = (struct entry*)malloc(sizeof(struct entry))))
		return (NULL);
	new->tterm = 0;
	new->nuses = 0;
	new->name = NULL;
	new->link = NULL;
	new->line = 0;
	return (new);
}

struct entry	*manage_entry(int macro)
{
	static struct entry	*current;

	if (macro == NEW)
		current = new_entry();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_entry: no decent macro\n", 30);
	return (NULL);
}
