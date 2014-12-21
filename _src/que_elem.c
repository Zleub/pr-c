#include <stdlib.h>
#include <string.h>
#include <search.h>

enum e_macro
{
	NEW,
	GET
};

struct que_elem	*new_que_elem(void)
{
	struct que_elem	*new;

	if (!(new = (struct que_elem*)malloc(sizeof(struct que_elem))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

struct que_elem	*manage_que_elem(int macro)
{
	static struct que_elem	*current;

	if (macro == NEW)
		current = new_que_elem();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_que_elem: no decent macro\n", 33);
	return (NULL);
}
