#include <stdlib.h>
#include <string.h>
#include <resolv.h>

enum e_macro
{
	NEW,
	GET
};

struct sockaddr_in	*new_sockaddr_in(void)
{
	struct sockaddr_in	*new;

	if (!(new = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in))))
		return (NULL);
	bzero((void*)(&new->nsaddr_list), sizeof() * MAXNS);
	new->id = 0;
	bzero((void*)(&new->dnsrch), sizeof(char*) * MAXDNSRCH+1);
	bzero((void*)(&new->defdname), sizeof(char) * 256);
	new->pfcode = 0;
	new->pfcode = 0;
	new->ndots:4 = 0;
	new->nsort:4 = 0;
	bzero((void*)(&new->unused), sizeof(char) * 3);
	bzero((void*)(&new->addr), sizeof(struct in_addr));
	new->mask = 0;
	return (new);
}

struct sockaddr_in	*manage_sockaddr_in(int macro)
{
	static struct sockaddr_in	*current;

	if (macro == NEW)
		current = new_sockaddr_in();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sockaddr_in: no decent macro\n", 36);
	return (NULL);
}
