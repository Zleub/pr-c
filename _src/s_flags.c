#include <stdlib.h>
#include <string.h>
#include <ft_printf.h>

enum e_macro
{
	NEW,
	GET
};

struct s_flags	*new_s_flags(void)
{
	struct s_flags	*new;

	if (!(new = (struct s_flags*)malloc(sizeof(struct s_flags))))
		return (NULL);
	new->minus = 0;
	new->plus = 0;
	new->zero = 0;
	new->space = 0;
	new->width = 0;
	new->cmp = 0;
	return (new);
}

struct s_flags	*manage_s_flags(int macro)
{
	static struct s_flags	*current;

	if (macro == NEW)
		current = new_s_flags();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_flags: no decent macro\n", 32);
	return (NULL);
}
