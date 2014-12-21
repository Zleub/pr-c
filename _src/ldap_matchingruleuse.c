#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_matchingruleuse	*new_ldap_matchingruleuse(void)
{
	struct ldap_matchingruleuse	*new;

	if (!(new = (struct ldap_matchingruleuse*)malloc(sizeof(struct ldap_matchingruleuse))))
		return (NULL);
	new->mru_oid = NULL;
	new->*mru_names = NULL;
	new->mru_desc = NULL;
	new->mru_obsolete = 0;
	new->*mru_applies_oids = NULL;
	new->*mru_extensions = NULL;
	return (new);
}

struct ldap_matchingruleuse	*manage_ldap_matchingruleuse(int macro)
{
	static struct ldap_matchingruleuse	*current;

	if (macro == NEW)
		current = new_ldap_matchingruleuse();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_matchingruleuse: no decent macro\n", 45);
	return (NULL);
}
