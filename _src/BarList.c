#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct BarList	*new_BarList(void)
{
	struct BarList	*new;

	if (!(new = (struct BarList*)malloc(sizeof(struct BarList))))
		return (NULL);
	new->listLength = 0;
	new->elements[] = 0;
	return (new);
}

struct BarList	*manage_BarList(int macro)
{
	static struct BarList	*current;

	if (macro == NEW)
		current = new_BarList();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_BarList: no decent macro\n", 32);
	return (NULL);
}
