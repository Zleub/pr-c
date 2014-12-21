#include <stdlib.h>
#include <string.h>
#include <tclTomMath.h>

enum e_macro
{
	NEW,
	GET
};

struct mp_int	*new_mp_int(void)
{
	struct mp_int	*new;

	if (!(new = (struct mp_int*)malloc(sizeof(struct mp_int))))
		return (NULL);
	new->used, alloc, sign = 0;
	new->dp = NULL;
	return (new);
}

struct mp_int	*manage_mp_int(int macro)
{
	static struct mp_int	*current;

	if (macro == NEW)
		current = new_mp_int();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_mp_int: no decent macro\n", 31);
	return (NULL);
}
