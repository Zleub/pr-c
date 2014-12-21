#include <stdlib.h>
#include <string.h>
#include <ifaddrs.h>

enum e_macro
{
	NEW,
	GET
};

struct ifaddrs	*new_ifaddrs(void)
{
	struct ifaddrs	*new;

	if (!(new = (struct ifaddrs*)malloc(sizeof(struct ifaddrs))))
		return (NULL);
	new->ifa_next = NULL;
	new->ifa_name = NULL;
	new->ifa_flags = 0;
	new->ifa_addr = NULL;
	new->ifa_netmask = NULL;
	new->ifa_dstaddr = NULL;
	new->ifa_data = NULL;
	return (new);
}

struct ifaddrs	*manage_ifaddrs(int macro)
{
	static struct ifaddrs	*current;

	if (macro == NEW)
		current = new_ifaddrs();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ifaddrs: no decent macro\n", 32);
	return (NULL);
}
