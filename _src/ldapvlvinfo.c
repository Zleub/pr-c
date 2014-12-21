#include <stdlib.h>
#include <string.h>
#include <ldap.h>

enum e_macro
{
	NEW,
	GET
};

struct ldapvlvinfo	*new_ldapvlvinfo(void)
{
	struct ldapvlvinfo	*new;

	if (!(new = (struct ldapvlvinfo*)malloc(sizeof(struct ldapvlvinfo))))
		return (NULL);
	new->ldvlv_version = 0;
	new->ldvlv_before_count = 0;
	new->ldvlv_after_count = 0;
	new->ldvlv_offset = 0;
	new->ldvlv_count = 0;
	new->	ldvlv_attrvalue = NULL;
	new->	ldvlv_context = NULL;
	new->			ldvlv_extradata = NULL;
	return (new);
}

struct ldapvlvinfo	*manage_ldapvlvinfo(int macro)
{
	static struct ldapvlvinfo	*current;

	if (macro == NEW)
		current = new_ldapvlvinfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ldapvlvinfo: no decent macro\n", 36);
	return (NULL);
}
