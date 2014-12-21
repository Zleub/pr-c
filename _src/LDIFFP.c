#include <stdlib.h>
#include <string.h>
#include <ldif.h>

enum e_macro
{
	NEW,
	GET
};

struct LDIFFP	*new_LDIFFP(void)
{
	struct LDIFFP	*new;

	if (!(new = (struct LDIFFP*)malloc(sizeof(struct LDIFFP))))
		return (NULL);
	new->fp = NULL;
	new->prev = NULL;
	return (new);
}

struct LDIFFP	*manage_LDIFFP(int macro)
{
	static struct LDIFFP	*current;

	if (macro == NEW)
		current = new_LDIFFP();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_LDIFFP: no decent macro\n", 31);
	return (NULL);
}
