#include <stdlib.h>
#include <string.h>
#include <netdb.h>

enum e_macro
{
	NEW,
	GET
};

struct hostent	*new_hostent(void)
{
	struct hostent	*new;

	if (!(new = (struct hostent*)malloc(sizeof(struct hostent))))
		return (NULL);
	new->h_name = NULL;
	new->*h_aliases = NULL;
	new->h_addrtype = 0;
	new->h_length = 0;
	new->*h_addr_list = NULL;
	return (new);
}

struct hostent	*manage_hostent(int macro)
{
	static struct hostent	*current;

	if (macro == NEW)
		current = new_hostent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_hostent: no decent macro\n", 32);
	return (NULL);
}
