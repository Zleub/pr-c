#include <stdlib.h>
#include <string.h>
#include <tic.h>

enum e_macro
{
	NEW,
	GET
};

struct name_table_entry	*new_name_table_entry(void)
{
	struct name_table_entry	*new;

	if (!(new = (struct name_table_entry*)malloc(sizeof(struct name_table_entry))))
		return (NULL);
	new->nte_name = NULL;
	new->nte_type = 0;
	new->nte_index = 0;
	new->nte_link = 0;
	return (new);
}

struct name_table_entry	*manage_name_table_entry(int macro)
{
	static struct name_table_entry	*current;

	if (macro == NEW)
		current = new_name_table_entry();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_name_table_entry: no decent macro\n", 41);
	return (NULL);
}
