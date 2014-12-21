#include <stdlib.h>
#include <string.h>
#include <term.h>

enum e_macro
{
	NEW,
	GET
};

struct termios	*new_termios(void)
{
	struct termios	*new;

	if (!(new = (struct termios*)malloc(sizeof(struct termios))))
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

struct termios	*manage_termios(int macro)
{
	static struct termios	*current;

	if (macro == NEW)
		current = new_termios();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_termios: no decent macro\n", 32);
	return (NULL);
}
