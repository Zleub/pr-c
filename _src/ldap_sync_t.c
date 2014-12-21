#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldap_sync_t	*new_ldap_sync_t(void)
{
	struct ldap_sync_t	*new;

	if (!(new = (struct ldap_sync_t*)malloc(sizeof(struct ldap_sync_t))))
		return (NULL);
	new->ls_base = NULL;
	new->ls_scope = 0;
	new->ls_filter = NULL;
	new->*ls_attrs = NULL;
	new->ls_timelimit = 0;
	new->ls_sizelimit = 0;
	new->ls_timeout = 0;
	new->ls_search_entry = 0;
	new->ls_search_reference = 0;
	new->ls_intermediate = 0;
	new->ls_search_result = 0;
	new->ls_private = NULL;
	new->ls_ld = NULL;
	new->ls_msgid = 0;
	new->ls_reloadHint = 0;
	bzero((void*)(&new->ls_cookie), sizeof(struct berval));
	new->ls_refreshPhase = 0;
	return (new);
}

struct ldap_sync_t	*manage_ldap_sync_t(int macro)
{
	static struct ldap_sync_t	*current;

	if (macro == NEW)
		current = new_ldap_sync_t();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldap_sync_t: no decent macro\n", 36);
	return (NULL);
}
