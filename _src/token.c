#include <stdlib.h>
#include <string.h>
#include <tic.h>

enum e_macro
{
	NEW,
	GET
};

struct token	*new_token(void)
{
	struct token	*new;

	if (!(new = (struct token*)malloc(sizeof(struct token))))
		return (NULL);
	new->tk_name = NULL;
	new->tk_valnumber = 0;
	new->tk_valstring = NULL;
	return (new);
}

struct token	*manage_token(int macro)
{
	static struct token	*current;

	if (macro == NEW)
		current = new_token();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_token: no decent macro\n", 30);
	return (NULL);
}
