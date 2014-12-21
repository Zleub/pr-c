#include <stdlib.h>
#include <string.h>
#include <nl_types.h>

enum e_macro
{
	NEW,
	GET
};

struct _nls_msg_hdr	*new__nls_msg_hdr(void)
{
	struct _nls_msg_hdr	*new;

	if (!(new = (struct _nls_msg_hdr*)malloc(sizeof(struct _nls_msg_hdr))))
		return (NULL);
	new->__msgno = 0;
	new->__msglen = 0;
	new->__offset = 0;
	return (new);
}

struct _nls_msg_hdr	*manage__nls_msg_hdr(int macro)
{
	static struct _nls_msg_hdr	*current;

	if (macro == NEW)
		current = new__nls_msg_hdr();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__nls_msg_hdr: no decent macro\n", 37);
	return (NULL);
}
