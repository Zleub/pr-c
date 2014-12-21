#include <stdlib.h>
#include <string.h>
#include <netdb.h>

enum e_macro
{
	NEW,
	GET
};

struct netent	*new_netent(void)
{
	struct netent	*new;

	if (!(new = (struct netent*)malloc(sizeof(struct netent))))
		return (NULL);
	new->n_name = NULL;
	new->*n_aliases = NULL;
	new->n_addrtype = 0;
	new->n_net = 0;
	return (new);
}

struct netent	*manage_netent(int macro)
{
	static struct netent	*current;

	if (macro == NEW)
		current = new_netent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_netent: no decent macro\n", 31);
	return (NULL);
}
