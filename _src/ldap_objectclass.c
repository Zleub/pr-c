#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_objectclass	*new_ldap_objectclass(void)
{
	struct ldap_objectclass	*new;

	if (!(new = (struct ldap_objectclass*)malloc(sizeof(struct ldap_objectclass))))
		return (NULL);
	new->oc_oid = NULL;
	new->*oc_names = NULL;
	new->oc_desc = NULL;
	new->oc_obsolete = 0;
	new->*oc_sup_oids = NULL;
	new->oc_kind = 0;
	new->*oc_at_oids_must = NULL;
	new->*oc_at_oids_may = NULL;
	new->*oc_extensions = NULL;
	return (new);
}

struct ldap_objectclass	*manage_ldap_objectclass(int macro)
{
	static struct ldap_objectclass	*current;

	if (macro == NEW)
		current = new_ldap_objectclass();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_objectclass: no decent macro\n", 41);
	return (NULL);
}
