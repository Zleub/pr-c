#include <stdlib.h>
#include <string.h>
#include <getopt.h>

enum e_macro
{
	NEW,
	GET
};

struct option	*new_option(void)
{
	struct option	*new;

	if (!(new = (struct option*)malloc(sizeof(struct option))))
		return (NULL);
	new->name = NULL;
	new->has_arg = 0;
	new->flag = NULL;
	new->val = 0;
	return (new);
}

struct option	*manage_option(int macro)
{
	static struct option	*current;

	if (macro == NEW)
		current = new_option();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_option: no decent macro\n", 31);
	return (NULL);
}
