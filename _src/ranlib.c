#include <stdlib.h>
#include <string.h>
#include <ranlib.h>

enum e_macro
{
	NEW,
	GET
};

struct ranlib	*new_ranlib(void)
{
	struct ranlib	*new;

	if (!(new = (struct ranlib*)malloc(sizeof(struct ranlib))))
		return (NULL);
	new->ran_strx = 0;
	new->ran_name = NULL;
	return (new);
}

struct ranlib	*manage_ranlib(int macro)
{
	static struct ranlib	*current;

	if (macro == NEW)
		current = new_ranlib();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ranlib: no decent macro\n", 31);
	return (NULL);
}
