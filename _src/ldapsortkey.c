#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldapsortkey	*new_ldapsortkey(void)
{
	struct ldapsortkey	*new;

	if (!(new = (struct ldapsortkey*)malloc(sizeof(struct ldapsortkey))))
		return (NULL);
	new->attributeType = NULL;
	new->orderingRule = NULL;
	new->reverseOrder = 0;
	return (new);
}

struct ldapsortkey	*manage_ldapsortkey(int macro)
{
	static struct ldapsortkey	*current;

	if (macro == NEW)
		current = new_ldapsortkey();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldapsortkey: no decent macro\n", 36);
	return (NULL);
}
