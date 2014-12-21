#include <stdlib.h>
#include <string.h>
#include <Xplugin.h>

enum e_macro
{
	NEW,
	GET
};

struct xp_box_struct	*new_xp_box_struct(void)
{
	struct xp_box_struct	*new;

	if (!(new = (struct xp_box_struct*)malloc(sizeof(struct xp_box_struct))))
		return (NULL);
	new->x1, y1, x2, y2 = 0;
	return (new);
}

struct xp_box_struct	*manage_xp_box_struct(int macro)
{
	static struct xp_box_struct	*current;

	if (macro == NEW)
		current = new_xp_box_struct();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_xp_box_struct: no decent macro\n", 38);
	return (NULL);
}
