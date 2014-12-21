#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_structurerule	*new_ldap_structurerule(void)
{
	struct ldap_structurerule	*new;

	if (!(new = (struct ldap_structurerule*)malloc(sizeof(struct ldap_structurerule))))
		return (NULL);
	new->sr_ruleid = 0;
	new->*sr_names = NULL;
	new->sr_desc = NULL;
	new->sr_obsolete = 0;
	new->sr_nameform = NULL;
	new->sr_nsup_ruleids = 0;
	new->sr_sup_ruleids = NULL;
	new->*sr_extensions = NULL;
	return (new);
}

struct ldap_structurerule	*manage_ldap_structurerule(int macro)
{
	static struct ldap_structurerule	*current;

	if (macro == NEW)
		current = new_ldap_structurerule();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_structurerule: no decent macro\n", 43);
	return (NULL);
}
