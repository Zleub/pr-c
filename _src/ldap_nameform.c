#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_nameform	*new_ldap_nameform(void)
{
	struct ldap_nameform	*new;

	if (!(new = (struct ldap_nameform*)malloc(sizeof(struct ldap_nameform))))
		return (NULL);
	new->nf_oid = NULL;
	new->*nf_names = NULL;
	new->nf_desc = NULL;
	new->nf_obsolete = 0;
	new->nf_objectclass = NULL;
	new->*nf_at_oids_must = NULL;
	new->*nf_at_oids_may = NULL;
	new->*nf_extensions = NULL;
	return (new);
}

struct ldap_nameform	*manage_ldap_nameform(int macro)
{
	static struct ldap_nameform	*current;

	if (macro == NEW)
		current = new_ldap_nameform();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_nameform: no decent macro\n", 38);
	return (NULL);
}
