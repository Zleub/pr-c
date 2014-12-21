#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct LDAPDerefVal	*new_LDAPDerefVal(void)
{
	struct LDAPDerefVal	*new;

	if (!(new = (struct LDAPDerefVal*)malloc(sizeof(struct LDAPDerefVal))))
		return (NULL);
	new->type = NULL;
	new->vals = 0;
	new->next = NULL;
	return (new);
}

struct LDAPDerefVal	*manage_LDAPDerefVal(int macro)
{
	static struct LDAPDerefVal	*current;

	if (macro == NEW)
		current = new_LDAPDerefVal();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_LDAPDerefVal: no decent macro\n", 37);
	return (NULL);
}
