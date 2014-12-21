#include <stdlib.h>
#include <string.h>
#include <netdb.h>

enum e_macro
{
	NEW,
	GET
};

struct protoent	*new_protoent(void)
{
	struct protoent	*new;

	if (!(new = (struct protoent*)malloc(sizeof(struct protoent))))
		return (NULL);
	new->p_name = NULL;
	new->*p_aliases = NULL;
	new->p_proto = 0;
	return (new);
}

struct protoent	*manage_protoent(int macro)
{
	static struct protoent	*current;

	if (macro == NEW)
		current = new_protoent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_protoent: no decent macro\n", 33);
	return (NULL);
}
