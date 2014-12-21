#include <stdlib.h>
#include <serveur.h>

struct s_env	*new_s_env(void)
{
	struct s_env	*new;

	if (!(new = (struct s_env*)malloc(sizeof(struct s_env))))
		return (NULL);
	new->this_char = 0;
	new->*this_str = 0;
	new->port = 0;
	new->x = 0;
	new->y = 0;
	new->clientmax = 0;
	new->*teams = 0;
	new->ipv4_socket = 0;
	new->sin = 0;
	new->active_fd_set = 0;
	return (new);
}

struct s_env	*manage_s_env(int macro)
{
	static struct s_env	*current;

	if (macro == NEW)
		current = new_s_env();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_env: no decent macro\n", 30);
	return (NULL);
}
