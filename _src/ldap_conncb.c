#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_conncb	*new_ldap_conncb(void)
{
	struct ldap_conncb	*new;

	if (!(new = (struct ldap_conncb*)malloc(sizeof(struct ldap_conncb))))
		return (NULL);
	new->lc_add = NULL;
	new->lc_del = NULL;
	new->lc_arg = NULL;
	return (new);
}

struct ldap_conncb	*manage_ldap_conncb(int macro)
{
	static struct ldap_conncb	*current;

	if (macro == NEW)
		current = new_ldap_conncb();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_conncb: no decent macro\n", 36);
	return (NULL);
}
