#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct Rect	*new_Rect(void)
{
	struct Rect	*new;

	if (!(new = (struct Rect*)malloc(sizeof(struct Rect))))
		return (NULL);
	new->top = 0;
	new->left = 0;
	new->bottom = 0;
	new->right = 0;
	return (new);
}

struct Rect	*manage_Rect(int macro)
{
	static struct Rect	*current;

	if (macro == NEW)
		current = new_Rect();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Rect: no decent macro\n", 29);
	return (NULL);
}
