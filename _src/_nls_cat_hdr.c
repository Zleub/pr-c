#include <stdlib.h>
#include <string.h>
#include <nl_types.h>

enum e_macro
{
	NEW,
	GET
};

struct _nls_cat_hdr	*new__nls_cat_hdr(void)
{
	struct _nls_cat_hdr	*new;

	if (!(new = (struct _nls_cat_hdr*)malloc(sizeof(struct _nls_cat_hdr))))
		return (NULL);
	new->__magic = 0;
	new->__nsets = 0;
	new->__mem = 0;
	new->__msg_hdr_offset = 0;
	new->__msg_txt_offset = 0;
	return (new);
}

struct _nls_cat_hdr	*manage__nls_cat_hdr(int macro)
{
	static struct _nls_cat_hdr	*current;

	if (macro == NEW)
		current = new__nls_cat_hdr();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__nls_cat_hdr: no decent macro\n", 37);
	return (NULL);
}
