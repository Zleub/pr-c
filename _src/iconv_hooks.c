#include <stdlib.h>
#include <string.h>
#include <iconv.h>

enum e_macro
{
	NEW,
	GET
};

struct iconv_hooks	*new_iconv_hooks(void)
{
	struct iconv_hooks	*new;

	if (!(new = (struct iconv_hooks*)malloc(sizeof(struct iconv_hooks))))
		return (NULL);
	new->uc_hook = 0;
	new->wc_hook = 0;
	new-> data = NULL;
	return (new);
}

struct iconv_hooks	*manage_iconv_hooks(int macro)
{
	static struct iconv_hooks	*current;

	if (macro == NEW)
		current = new_iconv_hooks();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_iconv_hooks: no decent macro\n", 36);
	return (NULL);
}
