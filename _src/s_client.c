#include <stdlib.h>
#include <serveur.h>

struct s_client	*new_s_client(void)
{
	struct s_client	*new;

	if (!(new = (struct s_client*)malloc(sizeof(struct s_client))))
		return (NULL);
	new->fd = 0;
	new->state = 0;
	new->sin = 0;
	return (new);
}

struct s_client	*manage_s_client(int macro)
{
	static struct s_client	*current;

	if (macro == NEW)
		current = new_s_client();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_client: no decent macro\n", 33);
	return (NULL);
}
urrent;

	if (macro == NEW)
		current = new_s_client();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_client: no decent macro\n", 33);
	return (NULL);
}