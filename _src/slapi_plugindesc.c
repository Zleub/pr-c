#include <stdlib.h>
#include <string.h>
#include <slapi-plugin.h>

enum e_macro
{
	NEW,
	GET
};

struct slapi_plugindesc	*new_slapi_plugindesc(void)
{
	struct slapi_plugindesc	*new;

	if (!(new = (struct slapi_plugindesc*)malloc(sizeof(struct slapi_plugindesc))))
		return (NULL);
	new->spd_id = NULL;
	new->spd_vendor = NULL;
	new->spd_version = NULL;
	new->spd_description = NULL;
	return (new);
}

struct slapi_plugindesc	*manage_slapi_plugindesc(int macro)
{
	static struct slapi_plugindesc	*current;

	if (macro == NEW)
		current = new_slapi_plugindesc();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_slapi_plugindesc: no decent macro\n", 41);
	return (NULL);
}
