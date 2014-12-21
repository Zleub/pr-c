#include <stdlib.h>
#include <string.h>
#include <printf.h>

enum e_macro
{
	NEW,
	GET
};

struct printf_info	*new_printf_info(void)
{
	struct printf_info	*new;

	if (!(new = (struct printf_info*)malloc(sizeof(struct printf_info))))
		return (NULL);
	new->context = NULL;
	new->loc = 0;
	new->vsep = 0;
	new-> one of ,: = NULL;
	new->prec = 0;
	new->width = 0;
	new->spec = 0;
	new->pad = 0;
	new->signchar = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->:1 = 0;
	new->sofar = 0;
	new->get_width = 0;
	new->get_prec = 0;
	new->begin = NULL;
	new->end = NULL;
	bzero((void*)(&new->arg), sizeof(void*) * __PRINTFMAXARG);
	return (new);
}

struct printf_info	*manage_printf_info(int macro)
{
	static struct printf_info	*current;

	if (macro == NEW)
		current = new_printf_info();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_printf_info: no decent macro\n", 36);
	return (NULL);
}
