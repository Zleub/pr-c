#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_apifeature_info	*new_ldap_apifeature_info(void)
{
	struct ldap_apifeature_info	*new;

	if (!(new = (struct ldap_apifeature_info*)malloc(sizeof(struct ldap_apifeature_info))))
		return (NULL);
	new->ldapaif_info_version = 0;
	new->ldapaif_version = 0;
	return (new);
}

struct ldap_apifeature_info	*manage_ldap_apifeature_info(int macro)
{
	static struct ldap_apifeature_info	*current;

	if (macro == NEW)
		current = new_ldap_apifeature_info();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_apifeature_info: no decent macro\n", 45);
	return (NULL);
}
