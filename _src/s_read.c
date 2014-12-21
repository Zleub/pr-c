#include <stdlib.h>
#include <libft.h>

struct s_read	*new_s_read(void)
{
	struct s_read	*new;

	if (!(new = (struct s_read*)malloc(sizeof(struct s_read))))
		return (NULL);
	new->size = 0;
	new->index = 0;
	new->fd = 0;
	new->read = NULL;
	new->next = NULL;
	return (new);
}

struct s_read	*manage_s_read(int macro)
{
	static struct s_read	*current;

	if (macro == NEW)
		current = new_s_read();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_read: no decent macro\n", 31);
	return (NULL);
}
