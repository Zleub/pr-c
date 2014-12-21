#include <stdlib.h>
#include <string.h>
#include <histedit.h>

enum e_macro
{
	NEW,
	GET
};

struct histeventW	*new_histeventW(void)
{
	struct histeventW	*new;

	if (!(new = (struct histeventW*)malloc(sizeof(struct histeventW))))
		return (NULL);
	new->num = 0;
	new->str = NULL;
	return (new);
}

struct histeventW	*manage_histeventW(int macro)
{
	static struct histeventW	*current;

	if (macro == NEW)
		current = new_histeventW();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_histeventW: no decent macro\n", 35);
	return (NULL);
}
