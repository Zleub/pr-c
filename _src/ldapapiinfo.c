#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldapapiinfo	*new_ldapapiinfo(void)
{
	struct ldapapiinfo	*new;

	if (!(new = (struct ldapapiinfo*)malloc(sizeof(struct ldapapiinfo))))
		return (NULL);
	new->ldapai_info_version = 0;
	new->ldapai_api_version = 0;
	new->ldapai_protocol_version = 0;
	new->*ldapai_extensions = NULL;
	new->ldapai_vendor_name = NULL;
	new->ldapai_vendor_version = 0;
	return (new);
}

struct ldapapiinfo	*manage_ldapapiinfo(int macro)
{
	static struct ldapapiinfo	*current;

	if (macro == NEW)
		current = new_ldapapiinfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldapapiinfo: no decent macro\n", 36);
	return (NULL);
}
