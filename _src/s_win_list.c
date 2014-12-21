#include <stdlib.h>
#include <curse.h>

struct s_win_list	*new_s_win_list(void)
{
	struct s_win_list	*new;

	if (!(new = (struct s_win_list*)malloc(sizeof(struct s_win_list))))
		return (NULL);
	new->*win = 0;
	new->*next = 0;
	return (new);
}

struct s_win_list	*manage_s_win_list(int macro)
{
	static struct s_win_list	*current;

	if (macro == NEW)
		current = new_s_win_list();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_win_list: no decent macro\n", 35);
	return (NULL);
}