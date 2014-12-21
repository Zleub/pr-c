#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldapcontrol	*new_ldapcontrol(void)
{
	struct ldapcontrol	*new;

	if (!(new = (struct ldapcontrol*)malloc(sizeof(struct ldapcontrol))))
		return (NULL);
	new->			ldctl_oid = NULL;
	bzero((void*)(&new->ldctl_value), sizeof(struct berval));
	new->ldctl_iscritical = 0;
	return (new);
}

struct ldapcontrol	*manage_ldapcontrol(int macro)
{
	static struct ldapcontrol	*current;

	if (macro == NEW)
		current = new_ldapcontrol();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldapcontrol: no decent macro\n", 36);
	return (NULL);
}
