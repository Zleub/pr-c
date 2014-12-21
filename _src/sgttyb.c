#include <stdlib.h>
#include <string.h>
#include <term.h>

enum e_macro
{
	NEW,
	GET
};

struct sgttyb	*new_sgttyb(void)
{
	struct sgttyb	*new;

	if (!(new = (struct sgttyb*)malloc(sizeof(struct sgttyb))))
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

struct sgttyb	*manage_sgttyb(int macro)
{
	static struct sgttyb	*current;

	if (macro == NEW)
		current = new_sgttyb();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sgttyb: no decent macro\n", 31);
	return (NULL);
}
