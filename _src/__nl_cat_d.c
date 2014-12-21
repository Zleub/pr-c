#include <stdlib.h>
#include <string.h>
#include <nl_types.h>

enum e_macro
{
	NEW,
	GET
};

struct __nl_cat_d	*new___nl_cat_d(void)
{
	struct __nl_cat_d	*new;

	if (!(new = (struct __nl_cat_d*)malloc(sizeof(struct __nl_cat_d))))
		return (NULL);
	new->__data = NULL;
	new->__size = 0;
	return (new);
}

struct __nl_cat_d	*manage___nl_cat_d(int macro)
{
	static struct __nl_cat_d	*current;

	if (macro == NEW)
		current = new___nl_cat_d();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage___nl_cat_d: no decent macro\n", 35);
	return (NULL);
}
