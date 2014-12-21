#include <stdlib.h>
#include <string.h>
#include <netdb.h>

enum e_macro
{
	NEW,
	GET
};

struct rpcent	*new_rpcent(void)
{
	struct rpcent	*new;

	if (!(new = (struct rpcent*)malloc(sizeof(struct rpcent))))
		return (NULL);
	new->r_name = NULL;
	new->*r_aliases = NULL;
	new->r_number = 0;
	return (new);
}

struct rpcent	*manage_rpcent(int macro)
{
	static struct rpcent	*current;

	if (macro == NEW)
		current = new_rpcent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_rpcent: no decent macro\n", 31);
	return (NULL);
}
