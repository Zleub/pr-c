#include <stdlib.h>
#include <string.h>
#include <netdb.h>

enum e_macro
{
	NEW,
	GET
};

struct servent	*new_servent(void)
{
	struct servent	*new;

	if (!(new = (struct servent*)malloc(sizeof(struct servent))))
		return (NULL);
	new->s_name = NULL;
	new->*s_aliases = NULL;
	new->s_port = 0;
	new->s_proto = NULL;
	return (new);
}

struct servent	*manage_servent(int macro)
{
	static struct servent	*current;

	if (macro == NEW)
		current = new_servent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_servent: no decent macro\n", 32);
	return (NULL);
}
