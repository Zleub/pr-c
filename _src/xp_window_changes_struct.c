#include <stdlib.h>
#include <string.h>
#include <Xplugin.h>

enum e_macro
{
	NEW,
	GET
};

struct xp_window_changes_struct	*new_xp_window_changes_struct(void)
{
	struct xp_window_changes_struct	*new;

	if (!(new = (struct xp_window_changes_struct*)malloc(sizeof(struct xp_window_changes_struct))))
		return (NULL);
	new->x, y = 0;
	new->width, height = 0;
	new->bit_gravity = 0;
	new->shape_nrects = 0;
	new->shape_rects = NULL;
	new->shape_tx, shape_ty = 0;
	new->stack_mode = 0;
	new->sibling = 0;
	new->depth = 0;
	new->colormap = NULL;
	new->colormap_data = NULL;
	new->window_level = 0;
	new->transient_for = 0;
	return (new);
}

struct xp_window_changes_struct	*manage_xp_window_changes_struct(int macro)
{
	static struct xp_window_changes_struct	*current;

	if (macro == NEW)
		current = new_xp_window_changes_struct();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_xp_window_changes_struct: no decent macro\n", 49);
	return (NULL);
}
