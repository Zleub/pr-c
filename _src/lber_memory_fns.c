#include <stdlib.h>
#include <string.h>
#include <lber.h>

enum e_macro
{
	NEW,
	GET
};

struct lber_memory_fns	*new_lber_memory_fns(void)
{
	struct lber_memory_fns	*new;

	if (!(new = (struct lber_memory_fns*)malloc(sizeof(struct lber_memory_fns))))
		return (NULL);
	new->bmf_malloc = NULL;
	new->bmf_calloc = NULL;
	new->bmf_realloc = NULL;
	new->bmf_free = NULL;
	return (new);
}

struct lber_memory_fns	*manage_lber_memory_fns(int macro)
{
	static struct lber_memory_fns	*current;

	if (macro == NEW)
		current = new_lber_memory_fns();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_lber_memory_fns: no decent macro\n", 40);
	return (NULL);
}
