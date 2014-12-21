#include <stdlib.h>
#include <string.h>
#include <nameser.h>

enum e_macro
{
	NEW,
	GET
};

struct __ns_rr	*new___ns_rr(void)
{
	struct __ns_rr	*new;

	if (!(new = (struct __ns_rr*)malloc(sizeof(struct __ns_rr))))
		return (NULL);
	bzero((void*)(&new->name), sizeof(char) * NS_MAXDNAME);
	new->type = 0;
	new->rr_class = 0;
	new->ttl = 0;
	new->rdlength = 0;
	new->	rdata = NULL;
	return (new);
}

struct __ns_rr	*manage___ns_rr(int macro)
{
	static struct __ns_rr	*current;

	if (macro == NEW)
		current = new___ns_rr();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage___ns_rr: no decent macro\n", 32);
	return (NULL);
}
