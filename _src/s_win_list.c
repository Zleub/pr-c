#include <stdlib.h>
#include <string.h>
#include <curse.h>

enum e_macro
{
	NEW,
	GET
};

struct s_win_list	*new_s_win_list(void)
{
	struct s_win_list	*new;

	if (!(new = (struct s_win_list*)malloc(sizeof(struct s_win_list))))
		return (NULL);
	new->win = NULL;
	new->next = NULL;
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
