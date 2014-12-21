#include <stdlib.h>
#include <string.h>
#include <term.h>

enum e_macro
{
	NEW,
	GET
};

struct term	*new_term(void)
{
	struct term	*new;

	if (!(new = (struct term*)malloc(sizeof(struct term))))
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

struct term	*manage_term(int macro)
{
	static struct term	*current;

	if (macro == NEW)
		current = new_term();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_term: no decent macro\n", 29);
	return (NULL);
}
