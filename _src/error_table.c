#include <stdlib.h>
#include <string.h>
#include <com_err.h>

enum e_macro
{
	NEW,
	GET
};

struct error_table	*new_error_table(void)
{
	struct error_table	*new;

	if (!(new = (struct error_table*)malloc(sizeof(struct error_table))))
		return (NULL);
	new-> const * const messages = NULL;
	new->base = 0;
	new->count = 0;
	return (new);
}

struct error_table	*manage_error_table(int macro)
{
	static struct error_table	*current;

	if (macro == NEW)
		current = new_error_table();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_error_table: no decent macro\n", 36);
	return (NULL);
}
