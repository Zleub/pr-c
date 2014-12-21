#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct FixedRect	*new_FixedRect(void)
{
	struct FixedRect	*new;

	if (!(new = (struct FixedRect*)malloc(sizeof(struct FixedRect))))
		return (NULL);
	new->left = 0;
	new->top = 0;
	new->right = 0;
	new->bottom = 0;
	return (new);
}

struct FixedRect	*manage_FixedRect(int macro)
{
	static struct FixedRect	*current;

	if (macro == NEW)
		current = new_FixedRect();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_FixedRect: no decent macro\n", 34);
	return (NULL);
}
