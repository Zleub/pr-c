#include <stdlib.h>
#include <libftsock_struct.h>

struct s_cbuff	*new_s_cbuff(void)
{
	struct s_cbuff	*new;

	if (!(new = (struct s_cbuff*)malloc(sizeof(struct s_cbuff))))
		return (NULL);
	new->data = NULL;
	new->size = 0;
	new->offset = 0;
	return (new);
}

struct s_cbuff	*manage_s_cbuff(int macro)
{
	static struct s_cbuff	*current;

	if (macro == NEW)
		current = new_s_cbuff();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_cbuff: no decent macro\n", 32);
	return (NULL);
}
