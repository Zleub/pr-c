#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_url_desc	*new_ldap_url_desc(void)
{
	struct ldap_url_desc	*new;

	if (!(new = (struct ldap_url_desc*)malloc(sizeof(struct ldap_url_desc))))
		return (NULL);
	new->lud_next = NULL;
	new->lud_scheme = NULL;
	new->lud_host = NULL;
	new->lud_port = 0;
	new->lud_dn = NULL;
	new->*lud_attrs = NULL;
	new->lud_scope = 0;
	new->lud_filter = NULL;
	new->*lud_exts = NULL;
	new->lud_crit_exts = 0;
	return (new);
}

struct ldap_url_desc	*manage_ldap_url_desc(int macro)
{
	static struct ldap_url_desc	*current;

	if (macro == NEW)
		current = new_ldap_url_desc();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_url_desc: no decent macro\n", 38);
	return (NULL);
}
