#include <stdlib.h>
#include <string.h>
#include <nlist.h>

enum e_macro
{
	NEW,
	GET
};

struct nlist	*new_nlist(void)
{
	struct nlist	*new;

	if (!(new = (struct nlist*)malloc(sizeof(struct nlist))))
		return (NULL);
	new->n_name = NULL;
	new->n_strx = 0;
	return (new);
}

struct nlist	*manage_nlist(int macro)
{
	static struct nlist	*current;

	if (macro == NEW)
		current = new_nlist();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_nlist: no decent macro\n", 30);
	return (NULL);
}
