#include <stdlib.h>
#include <string.h>
#include <tic.h>

enum e_macro
{
	NEW,
	GET
};

struct alias	*new_alias(void)
{
	struct alias	*new;

	if (!(new = (struct alias*)malloc(sizeof(struct alias))))
		return (NULL);
	new->from = NULL;
	new->to = NULL;
	new->source = NULL;
	return (new);
}

struct alias	*manage_alias(int macro)
{
	static struct alias	*current;

	if (macro == NEW)
		current = new_alias();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_alias: no decent macro\n", 30);
	return (NULL);
}
