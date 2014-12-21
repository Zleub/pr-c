#include <stdlib.h>
#include <string.h>
#include <disktab.h>

enum e_macro
{
	NEW,
	GET
};

struct partition	*new_partition(void)
{
	struct partition	*new;

	if (!(new = (struct partition*)malloc(sizeof(struct partition))))
		return (NULL);
	new->p_size = 0;
	new->p_bsize = 0;
	new->p_fsize = 0;
	return (new);
}

struct partition	*manage_partition(int macro)
{
	static struct partition	*current;

	if (macro == NEW)
		current = new_partition();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_partition: no decent macro\n", 34);
	return (NULL);
}
