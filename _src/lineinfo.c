#include <stdlib.h>
#include <string.h>
#include <histedit.h>

enum e_macro
{
	NEW,
	GET
};

struct lineinfo	*new_lineinfo(void)
{
	struct lineinfo	*new;

	if (!(new = (struct lineinfo*)malloc(sizeof(struct lineinfo))))
		return (NULL);
	new->buffer = NULL;
	new->cursor = NULL;
	new->lastchar = NULL;
	return (new);
}

struct lineinfo	*manage_lineinfo(int macro)
{
	static struct lineinfo	*current;

	if (macro == NEW)
		current = new_lineinfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_lineinfo: no decent macro\n", 33);
	return (NULL);
}
