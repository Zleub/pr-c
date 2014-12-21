#include <stdlib.h>
#include <string.h>
#include <ftw.h>

enum e_macro
{
	NEW,
	GET
};

struct FTW	*new_FTW(void)
{
	struct FTW	*new;

	if (!(new = (struct FTW*)malloc(sizeof(struct FTW))))
		return (NULL);
	new->base = 0;
	new->level = 0;
	return (new);
}

struct FTW	*manage_FTW(int macro)
{
	static struct FTW	*current;

	if (macro == NEW)
		current = new_FTW();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_FTW: no decent macro\n", 28);
	return (NULL);
}
