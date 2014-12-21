#include <stdlib.h>
#include <header.h>

struct s_hugo	*new_s_hugo(void)
{
	struct s_hugo	*new;

	if (!(new = (struct s_hugo*)malloc(sizeof(struct s_hugo))))
		return (NULL);
	new->*name = 0;
	new->height = 0;
	new->weight = 0;
	new->*pointofview = 0;
	return (new);
}

struct s_hugo	*manage_s_hugo(int macro)
{
	static struct s_hugo	*current;

	if (macro == NEW)
		current = new_s_hugo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_hugo: no decent macro\n", 31);
	return (NULL);
}