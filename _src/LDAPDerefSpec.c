#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct LDAPDerefSpec	*new_LDAPDerefSpec(void)
{
	struct LDAPDerefSpec	*new;

	if (!(new = (struct LDAPDerefSpec*)malloc(sizeof(struct LDAPDerefSpec))))
		return (NULL);
	new->derefAttr = NULL;
	new->*attributes = NULL;
	return (new);
}

struct LDAPDerefSpec	*manage_LDAPDerefSpec(int macro)
{
	static struct LDAPDerefSpec	*current;

	if (macro == NEW)
		current = new_LDAPDerefSpec();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_LDAPDerefSpec: no decent macro\n", 38);
	return (NULL);
}
