#include <stdlib.h>
#include <string.h>
#include <pwd.h>

enum e_macro
{
	NEW,
	GET
};

struct passwd	*new_passwd(void)
{
	struct passwd	*new;

	if (!(new = (struct passwd*)malloc(sizeof(struct passwd))))
		return (NULL);
	new->pw_name = NULL;
	new->pw_passwd = NULL;
	new->pw_uid = 0;
	new->pw_gid = 0;
	new->pw_change = 0;
	new->pw_class = NULL;
	new->pw_gecos = NULL;
	new->pw_dir = NULL;
	new->pw_shell = NULL;
	new->pw_expire = 0;
	return (new);
}

struct passwd	*manage_passwd(int macro)
{
	static struct passwd	*current;

	if (macro == NEW)
		current = new_passwd();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_passwd: no decent macro\n", 31);
	return (NULL);
}
