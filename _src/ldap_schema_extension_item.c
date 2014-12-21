#include <stdlib.h>
#include <string.h>
#include <ldap_schema.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_schema_extension_item	*new_ldap_schema_extension_item(void)
{
	struct ldap_schema_extension_item	*new;

	if (!(new = (struct ldap_schema_extension_item*)malloc(sizeof(struct ldap_schema_extension_item))))
		return (NULL);
	new->lsei_name = NULL;
	new->*lsei_values = NULL;
	return (new);
}

struct ldap_schema_extension_item	*manage_ldap_schema_extension_item(int macro)
{
	static struct ldap_schema_extension_item	*current;

	if (macro == NEW)
		current = new_ldap_schema_extension_item();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_schema_extension_item: no decent macro\n", 51);
	return (NULL);
}
