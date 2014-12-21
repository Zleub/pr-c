#include <stdlib.h>
#include <string.h>
#include <term.h>

enum e_macro
{
	NEW,
	GET
};

struct termio	*new_termio(void)
{
	struct termio	*new;

	if (!(new = (struct termio*)malloc(sizeof(struct termio))))
		return (NULL);
	new->term_names = NULL;
	new->str_table = NULL;
	new->Booleans = NULL;
	new->Numbers = NULL;
	new->*Strings = NULL;
	new->ext_str_table = NULL;
	new->*ext_Names = NULL;
	new->num_Booleans = 0;
	new->num_Numbers = 0;
	new->num_Strings = 0;
	new->ext_Booleans = 0;
	new->ext_Numbers = 0;
	new->ext_Strings = 0;
	return (new);
}

struct termio	*manage_termio(int macro)
{
	static struct termio	*current;

	if (macro == NEW)
		current = new_termio();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_termio: no decent macro\n", 31);
	return (NULL);
}
