#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_matchingrule	*new_ldap_matchingrule(void)
{
	struct ldap_matchingrule	*new;

	if (!(new = (struct ldap_matchingrule*)malloc(sizeof(struct ldap_matchingrule))))
		return (NULL);
	new->mr_oid = NULL;
	new->*mr_names = NULL;
	new->mr_desc = NULL;
	new->mr_obsolete = 0;
	new->mr_syntax_oid = NULL;
	new->*mr_extensions = NULL;
	return (new);
}

struct ldap_matchingrule	*manage_ldap_matchingrule(int macro)
{
	static struct ldap_matchingrule	*current;

	if (macro == NEW)
		current = new_ldap_matchingrule();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_matchingrule: no decent macro\n", 42);
	return (NULL);
}
