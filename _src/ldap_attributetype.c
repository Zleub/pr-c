#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_attributetype	*new_ldap_attributetype(void)
{
	struct ldap_attributetype	*new;

	if (!(new = (struct ldap_attributetype*)malloc(sizeof(struct ldap_attributetype))))
		return (NULL);
	new->at_oid = NULL;
	new->*at_names = NULL;
	new->at_desc = NULL;
	new->at_obsolete = 0;
	new->at_sup_oid = NULL;
	new->at_equality_oid = NULL;
	new->at_ordering_oid = NULL;
	new->at_substr_oid = NULL;
	new->at_syntax_oid = NULL;
	new->at_syntax_len = 0;
	new->at_single_value = 0;
	new->at_collective = 0;
	new->at_no_user_mod = 0;
	new->at_usage = 0;
	new->*at_extensions = NULL;
	return (new);
}

struct ldap_attributetype	*manage_ldap_attributetype(int macro)
{
	static struct ldap_attributetype	*current;

	if (macro == NEW)
		current = new_ldap_attributetype();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_attributetype: no decent macro\n", 43);
	return (NULL);
}
