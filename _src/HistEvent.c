#include <stdlib.h>
#include <string.h>
#include <histedit.h>

enum e_macro
{
	NEW,
	GET
};

struct HistEvent	*new_HistEvent(void)
{
	struct HistEvent	*new;

	if (!(new = (struct HistEvent*)malloc(sizeof(struct HistEvent))))
		return (NULL);
	new->num = 0;
	new->str = NULL;
	return (new);
}

struct HistEvent	*manage_HistEvent(int macro)
{
	static struct HistEvent	*current;

	if (macro == NEW)
		current = new_HistEvent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_HistEvent: no decent macro\n", 34);
	return (NULL);
}
