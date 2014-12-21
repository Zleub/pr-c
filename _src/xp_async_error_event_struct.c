#include <stdlib.h>
#include <string.h>
#include <Xplugin.h>

enum e_macro
{
	NEW,
	GET
};

struct xp_async_error_event_struct	*new_xp_async_error_event_struct(void)
{
	struct xp_async_error_event_struct	*new;

	if (!(new = (struct xp_async_error_event_struct*)malloc(sizeof(struct xp_async_error_event_struct))))
		return (NULL);
	new->request_type = 0;
	new->id = 0;
	new->error = 0;
	return (new);
}

struct xp_async_error_event_struct	*manage_xp_async_error_event_struct(int macro)
{
	static struct xp_async_error_event_struct	*current;

	if (macro == NEW)
		current = new_xp_async_error_event_struct();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_xp_async_error_event_struct: no decent macro\n", 52);
	return (NULL);
}
