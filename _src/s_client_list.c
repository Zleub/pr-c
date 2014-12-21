#include <stdlib.h>
#include <serveur.h>

struct s_client_list	*new_s_client_list(void)
{
	struct s_client_list	*new;

	if (!(new = (struct s_client_list*)malloc(sizeof(struct s_client_list))))
		return (NULL);
	new->*elem = 0;
	new->*next = 0;
	return (new);
}

struct s_client_list	*manage_s_client_list(int macro)
{
	static struct s_client_list	*current;

	if (macro == NEW)
		current = new_s_client_list();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_client_list: no decent macro\n", 38);
	return (NULL);
}
