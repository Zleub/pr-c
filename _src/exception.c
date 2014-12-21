#include <stdlib.h>
#include <string.h>
#include <math.h>

enum e_macro
{
	NEW,
	GET
};

struct exception	*new_exception(void)
{
	struct exception	*new;

	if (!(new = (struct exception*)malloc(sizeof(struct exception))))
		return (NULL);
	new->type = 0;
	new->name = NULL;
	new->arg1 = 0;
	new->arg2 = 0;
	new->retval = 0;
	return (new);
}

struct exception	*manage_exception(int macro)
{
	static struct exception	*current;

	if (macro == NEW)
		current = new_exception();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_exception: no decent macro\n", 34);
	return (NULL);
}
