#include <stdlib.h>
#include <string.h>
#include <lber.h>

enum e_macro
{
	NEW,
	GET
};

struct berval	*new_berval(void)
{
	struct berval	*new;

	if (!(new = (struct berval*)malloc(sizeof(struct berval))))
		return (NULL);
	new->bv_len = 0;
	new->bv_val = NULL;
	return (new);
}

struct berval	*manage_berval(int macro)
{
	static struct berval	*current;

	if (macro == NEW)
		current = new_berval();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_berval: no decent macro\n", 31);
	return (NULL);
}
