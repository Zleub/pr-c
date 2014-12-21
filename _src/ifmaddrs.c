#include <stdlib.h>
#include <string.h>
#include <ifaddrs.h>

enum e_macro
{
	NEW,
	GET
};

struct ifmaddrs	*new_ifmaddrs(void)
{
	struct ifmaddrs	*new;

	if (!(new = (struct ifmaddrs*)malloc(sizeof(struct ifmaddrs))))
		return (NULL);
	new->ifma_next = NULL;
	new->ifma_name = NULL;
	new->ifma_addr = NULL;
	new->ifma_lladdr = NULL;
	return (new);
}

struct ifmaddrs	*manage_ifmaddrs(int macro)
{
	static struct ifmaddrs	*current;

	if (macro == NEW)
		current = new_ifmaddrs();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ifmaddrs: no decent macro\n", 33);
	return (NULL);
}
