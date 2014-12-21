#include <stdlib.h>
#include <string.h>
#include <header.h>

enum e_macro
{
	NEW,
	GET
};

struct s_t1	*new_s_t1(void)
{
	struct s_t1	*new;

	if (!(new = (struct s_t1*)malloc(sizeof(struct s_t1))))
		return (NULL);
	new->id = 0;
	new->x = 0;
	new->y = 0;
	new->c = 0;
	new->s = NULL;
	bzero((void*)(&new->neibourghs), sizeof(struct s_t1*) * 10);
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
