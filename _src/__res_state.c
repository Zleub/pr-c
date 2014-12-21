#include <stdlib.h>
#include <string.h>
#include <resolv.h>

enum e_macro
{
	NEW,
	GET
};

struct __res_state	*new___res_state(void)
{
	struct __res_state	*new;

	if (!(new = (struct __res_state*)malloc(sizeof(struct __res_state))))
		return (NULL);
	new->retrans = 0;
	new->retry = 0;
	new->options = 0;
	new->options = 0;
	new->nscount = 0;
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

struct __res_state	*manage___res_state(int macro)
{
	static struct __res_state	*current;

	if (macro == NEW)
		current = new___res_state();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage___res_state: no decent macro\n", 36);
	return (NULL);
}
