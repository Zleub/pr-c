#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct wide	*new_wide(void)
{
	struct wide	*new;

	if (!(new = (struct wide*)malloc(sizeof(struct wide))))
		return (NULL);
	new->hi = 0;
	new->lo = 0;
	return (new);
}

struct wide	*manage_wide(int macro)
{
	static struct wide	*current;

	if (macro == NEW)
		current = new_wide();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_wide: no decent macro\n", 29);
	return (NULL);
}
