#include <stdlib.h>
#include <string.h>
#include <panel.h>

enum e_macro
{
	NEW,
	GET
};

struct panel	*new_panel(void)
{
	struct panel	*new;

	if (!(new = (struct panel*)malloc(sizeof(struct panel))))
		return (NULL);
	new->win = NULL;
	new->below = NULL;
	new->above = NULL;
	new->user = NULL;
	return (new);
}

struct panel	*manage_panel(int macro)
{
	static struct panel	*current;

	if (macro == NEW)
		current = new_panel();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_panel: no decent macro\n", 30);
	return (NULL);
}
