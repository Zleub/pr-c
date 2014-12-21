#include <stdlib.h>
#include <string.h>
#include <dtrace.h>

enum e_macro
{
	NEW,
	GET
};

struct dtrace_objinfo	*new_dtrace_objinfo(void)
{
	struct dtrace_objinfo	*new;

	if (!(new = (struct dtrace_objinfo*)malloc(sizeof(struct dtrace_objinfo))))
		return (NULL);
	new->dto_name = NULL;
	new->dto_file = NULL;
	new->dto_id = 0;
	new->dto_flags = 0;
	new->dto_text_va = 0;
	new->dto_text_size = 0;
	new->dto_data_va = 0;
	new->dto_data_size = 0;
	new->dto_bss_va = 0;
	new->dto_bss_size = 0;
	return (new);
}

struct dtrace_objinfo	*manage_dtrace_objinfo(int macro)
{
	static struct dtrace_objinfo	*current;

	if (macro == NEW)
		current = new_dtrace_objinfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dtrace_objinfo: no decent macro\n", 39);
	return (NULL);
}
