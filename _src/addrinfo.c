#include <stdlib.h>
#include <string.h>
#include <netdb.h>

enum e_macro
{
	NEW,
	GET
};

struct addrinfo	*new_addrinfo(void)
{
	struct addrinfo	*new;

	if (!(new = (struct addrinfo*)malloc(sizeof(struct addrinfo))))
		return (NULL);
	new->ai_flags = 0;
	new->ai_family = 0;
	new->ai_socktype = 0;
	new->ai_protocol = 0;
	new->ai_addrlen = 0;
	new->ai_canonname = NULL;
	new->ai_addr = NULL;
	new->ai_next = NULL;
	return (new);
}

struct addrinfo	*manage_addrinfo(int macro)
{
	static struct addrinfo	*current;

	if (macro == NEW)
		current = new_addrinfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_addrinfo: no decent macro\n", 33);
	return (NULL);
}
