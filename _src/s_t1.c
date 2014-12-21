#include <stdlib.h>
#include <header2.h>

struct s_t1	*new_s_t1(void)
{
	struct s_t1	*new;

	if (!(new = (struct s_t1*)malloc(sizeof(struct s_t1))))
		return (NULL);
	new->id = 0;
	new->x = 0;
	new->y = 0;
	new->c = 0;
	new->s = 0;
	new->neibourghs[10] = NULL;
	return (new);
}

struct s_t1	*manage_s_t1(int macro)
{
	static struct s_t1	*current;

	if (macro == NEW)
		current = new_s_t1();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_t1: no decent macro\n", 29);
	return (NULL);
}
}
