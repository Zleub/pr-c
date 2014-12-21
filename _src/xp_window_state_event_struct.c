#include <stdlib.h>
#include <string.h>
#include <Xplugin.h>

enum e_macro
{
	NEW,
	GET
};

struct xp_window_state_event_struct	*new_xp_window_state_event_struct(void)
{
	struct xp_window_state_event_struct	*new;

	if (!(new = (struct xp_window_state_event_struct*)malloc(sizeof(struct xp_window_state_event_struct))))
		return (NULL);
	new->id = 0;
	new->state = 0;
	return (new);
}

struct xp_window_state_event_struct	*manage_xp_window_state_event_struct(int macro)
{
	static struct xp_window_state_event_struct	*current;

	if (macro == NEW)
		current = new_xp_window_state_event_struct();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_xp_window_state_event_struct: no decent macro\n", 53);
	return (NULL);
}
