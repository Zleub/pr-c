#include <stdlib.h>
#include <libftsock_struct.h>

struct s_tcpsock	*new_s_tcpsock(void)
{
	struct s_tcpsock	*new;

	if (!(new = (struct s_tcpsock*)malloc(sizeof(struct s_tcpsock))))
		return (NULL);
	new->sin = 0;
	new->sock = 0;
	new->ip = NULL;
	new->port = 0;
	new->backlog = 0;
	new->type = 0;
	new->error = 0;
	return (new);
}

struct s_tcpsock	*manage_s_tcpsock(int macro)
{
	static struct s_tcpsock	*current;

	if (macro == NEW)
		current = new_s_tcpsock();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_tcpsock: no decent macro\n", 34);
	return (NULL);
}
