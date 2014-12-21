#include <stdlib.h>
#include <string.h>
#include <libunwind.h>

enum e_macro
{
	NEW,
	GET
};

struct unw_proc_info_t	*new_unw_proc_info_t(void)
{
	struct unw_proc_info_t	*new;

	if (!(new = (struct unw_proc_info_t*)malloc(sizeof(struct unw_proc_info_t))))
		return (NULL);
	new->start_ip = 0;
	new->end_ip = 0;
	new->lsda = 0;
	new->handler = 0;
	new->gp = 0;
	new->flags = 0;
	new->format = 0;
	new->unwind_info_size = 0;
	new->unwind_info = 0;
	new->extra = 0;
	return (new);
}

struct unw_proc_info_t	*manage_unw_proc_info_t(int macro)
{
	static struct unw_proc_info_t	*current;

	if (macro == NEW)
		current = new_unw_proc_info_t();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_unw_proc_info_t: no decent macro\n", 40);
	return (NULL);
}
