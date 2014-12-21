#include <stdlib.h>
#include <string.h>
#include <expat.h>

enum e_macro
{
	NEW,
	GET
};

struct XML_cp	*new_XML_cp(void)
{
	struct XML_cp	*new;

	if (!(new = (struct XML_cp*)malloc(sizeof(struct XML_cp))))
		return (NULL);
	new->type = 0;
	new->quant = 0;
	new->                    name = NULL;
	new->numchildren = 0;
	new->                 children = NULL;
	return (new);
}

struct XML_cp	*manage_XML_cp(int macro)
{
	static struct XML_cp	*current;

	if (macro == NEW)
		current = new_XML_cp();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_XML_cp: no decent macro\n", 31);
	return (NULL);
}
