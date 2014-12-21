#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldapmod	*new_ldapmod(void)
{
	struct ldapmod	*new;

	if (!(new = (struct ldapmod*)malloc(sizeof(struct ldapmod))))
		return (NULL);
	new->mod_op = 0;
	new->mod_type = NULL;
	new->*modv_strvals = NULL;
	new->*modv_bvals = NULL;
	return (new);
}

struct ldapmod	*manage_ldapmod(int macro)
{
	static struct ldapmod	*current;

	if (macro == NEW)
		current = new_ldapmod();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldapmod: no decent macro\n", 32);
	return (NULL);
}
