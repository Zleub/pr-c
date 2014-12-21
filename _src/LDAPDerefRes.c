#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct LDAPDerefRes	*new_LDAPDerefRes(void)
{
	struct LDAPDerefRes	*new;

	if (!(new = (struct LDAPDerefRes*)malloc(sizeof(struct LDAPDerefRes))))
		return (NULL);
	new->derefAttr = NULL;
	bzero((void*)(&new->derefVal), sizeof(struct berval));
	new->attrVals = NULL;
	new->next = NULL;
	return (new);
}

struct LDAPDerefRes	*manage_LDAPDerefRes(int macro)
{
	static struct LDAPDerefRes	*current;

	if (macro == NEW)
		current = new_LDAPDerefRes();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_LDAPDerefRes: no decent macro\n", 37);
	return (NULL);
}
