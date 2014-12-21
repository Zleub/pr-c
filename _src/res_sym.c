#include <stdlib.h>
#include <string.h>
#include <resolv.h>

enum e_macro
{
	NEW,
	GET
};

struct res_sym	*new_res_sym(void)
{
	struct res_sym	*new;

	if (!(new = (struct res_sym*)malloc(sizeof(struct res_sym))))
		return (NULL);
	new->number = 0;
	new->	name = NULL;
	new->	humanname = NULL;
	return (new);
}

struct res_sym	*manage_res_sym(int macro)
{
	static struct res_sym	*current;

	if (macro == NEW)
		current = new_res_sym();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_res_sym: no decent macro\n", 32);
	return (NULL);
}
