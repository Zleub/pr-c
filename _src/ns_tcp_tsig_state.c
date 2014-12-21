#include <stdlib.h>
#include <string.h>
#include <nameser.h>

enum e_macro
{
	NEW,
	GET
};

struct ns_tcp_tsig_state	*new_ns_tcp_tsig_state(void)
{
	struct ns_tcp_tsig_state	*new;

	if (!(new = (struct ns_tcp_tsig_state*)malloc(sizeof(struct ns_tcp_tsig_state))))
		return (NULL);
	new->counter = 0;
	new->key = NULL;
	new->ctx = NULL;
	bzero((void*)(&new->sig), sizeof(unsigned char) * NS_PACKETSZ);
	new->siglen = 0;
	return (new);
}

struct ns_tcp_tsig_state	*manage_ns_tcp_tsig_state(int macro)
{
	static struct ns_tcp_tsig_state	*current;

	if (macro == NEW)
		current = new_ns_tcp_tsig_state();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ns_tcp_tsig_state: no decent macro\n", 42);
	return (NULL);
}
