#include <stdlib.h>
#include <string.h>
#include <nl_types.h>

enum e_macro
{
	NEW,
	GET
};

struct _nls_set_hdr	*new__nls_set_hdr(void)
{
	struct _nls_set_hdr	*new;

	if (!(new = (struct _nls_set_hdr*)malloc(sizeof(struct _nls_set_hdr))))
		return (NULL);
	new->__setno = 0;
	new->__nmsgs = 0;
	new->__index = 0;
	return (new);
}

struct _nls_set_hdr	*manage__nls_set_hdr(int macro)
{
	static struct _nls_set_hdr	*current;

	if (macro == NEW)
		current = new__nls_set_hdr();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__nls_set_hdr: no decent macro\n", 37);
	return (NULL);
}
