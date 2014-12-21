#include <stdlib.h>
#include <string.h>
#include <serveur.h>

enum e_macro
{
	NEW,
	GET
};

struct s_env	*new_s_env(void)
{
	struct s_env	*new;

	if (!(new = (struct s_env*)malloc(sizeof(struct s_env))))
		return (NULL);
	new->this_char = 0;
	new->this_str = NULL;
	new->port = 0;
	new->x = 0;
	new->y = 0;
	new->clientmax = 0;
	new->teams = NULL;
	new->ipv4_socket = 0;
	bzero((void*)(&new->sin), sizeof(struct sockaddr_in));
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
