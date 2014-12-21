#include <stdlib.h>
#include <string.h>
#include <nameser.h>

enum e_macro
{
	NEW,
	GET
};

struct ns_tsig_key	*new_ns_tsig_key(void)
{
	struct ns_tsig_key	*new;

	if (!(new = (struct ns_tsig_key*)malloc(sizeof(struct ns_tsig_key))))
		return (NULL);
	bzero((void*)(&new->name[NS_MAXDNAME], alg), sizeof(char) * NS_MAXDNAME);
	new->data = NULL;
	new->len = 0;
	return (new);
}

struct ns_tsig_key	*manage_ns_tsig_key(int macro)
{
	static struct ns_tsig_key	*current;

	if (macro == NEW)
		current = new_ns_tsig_key();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ns_tsig_key: no decent macro\n", 36);
	return (NULL);
}
