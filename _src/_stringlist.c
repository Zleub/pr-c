#include <stdlib.h>
#include <string.h>
#include <stringlist.h>

enum e_macro
{
	NEW,
	GET
};

struct _stringlist	*new__stringlist(void)
{
	struct _stringlist	*new;

	if (!(new = (struct _stringlist*)malloc(sizeof(struct _stringlist))))
		return (NULL);
	new->*sl_str = NULL;
	new->sl_max = 0;
	new->sl_cur = 0;
	return (new);
}

struct _stringlist	*manage__stringlist(int macro)
{
	static struct _stringlist	*current;

	if (macro == NEW)
		current = new__stringlist();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__stringlist: no decent macro\n", 36);
	return (NULL);
}
