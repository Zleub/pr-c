#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_syntax	*new_ldap_syntax(void)
{
	struct ldap_syntax	*new;

	if (!(new = (struct ldap_syntax*)malloc(sizeof(struct ldap_syntax))))
		return (NULL);
	new->syn_oid = NULL;
	new->*syn_names = NULL;
	new->syn_desc = NULL;
	new->*syn_extensions = NULL;
	return (new);
}

struct ldap_syntax	*manage_ldap_syntax(int macro)
{
	static struct ldap_syntax	*current;

	if (macro == NEW)
		current = new_ldap_syntax();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_syntax: no decent macro\n", 36);
	return (NULL);
}
