#include <stdlib.h>
#include <serveur.h>

struct s_team_list	*new_s_team_list(void)
{
	struct s_team_list	*new;

	if (!(new = (struct s_team_list*)malloc(sizeof(struct s_team_list))))
		return (NULL);
	new->elem = NULL;
	new->slots = 0;
	new->players = NULL;
	new->next = NULL;
	return (new);
}

struct s_team_list	*manage_s_team_list(int macro)
{
	static struct s_team_list	*current;

	if (macro == NEW)
		current = new_s_team_list();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_team_list: no decent macro\n", 36);
	return (NULL);
}
