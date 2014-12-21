#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_contentrule	*new_ldap_contentrule(void)
{
	struct ldap_contentrule	*new;

	if (!(new = (struct ldap_contentrule*)malloc(sizeof(struct ldap_contentrule))))
		return (NULL);
	new->cr_oid = NULL;
	new->*cr_names = NULL;
	new->cr_desc = NULL;
	new->*cr_sup_oids = NULL;
	new->cr_obsolete = 0;
	new->*cr_oc_oids_aux = NULL;
	new->*cr_at_oids_must = NULL;
	new->*cr_at_oids_may = NULL;
	new->*cr_at_oids_not = NULL;
	new->*cr_extensions = NULL;
	return (new);
}

struct ldap_contentrule	*manage_ldap_contentrule(int macro)
{
	static struct ldap_contentrule	*current;

	if (macro == NEW)
		current = new_ldap_contentrule();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_contentrule: no decent macro\n", 41);
	return (NULL);
}
