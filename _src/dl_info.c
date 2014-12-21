#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

enum e_macro
{
	NEW,
	GET
};

struct dl_info	*new_dl_info(void)
{
	struct dl_info	*new;

	if (!(new = (struct dl_info*)malloc(sizeof(struct dl_info))))
		return (NULL);
	new->dli_fname = NULL;
	new->dli_fbase = NULL;
	new->dli_sname = NULL;
	new->dli_saddr = NULL;
	return (new);
}

struct dl_info	*manage_dl_info(int macro)
{
	static struct dl_info	*current;

	if (macro == NEW)
		current = new_dl_info();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dl_info: no decent macro\n", 32);
	return (NULL);
}
