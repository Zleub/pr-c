#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_ava	*new_ldap_ava(void)
{
	struct ldap_ava	*new;

	if (!(new = (struct ldap_ava*)malloc(sizeof(struct ldap_ava))))
		return (NULL);
	bzero((void*)(&new->la_attr), sizeof(struct berval));
	bzero((void*)(&new->la_value), sizeof(struct berval));
	new->la_flags = 0;
	new->la_private = NULL;
	return (new);
}

struct ldap_ava	*manage_ldap_ava(int macro)
{
	static struct ldap_ava	*current;

	if (macro == NEW)
		current = new_ldap_ava();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_ava: no decent macro\n", 33);
	return (NULL);
}
