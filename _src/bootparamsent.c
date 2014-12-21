#include <stdlib.h>
#include <string.h>
#include <bootparams.h>

enum e_macro
{
	NEW,
	GET
};

struct bootparamsent	*new_bootparamsent(void)
{
	struct bootparamsent	*new;

	if (!(new = (struct bootparamsent*)malloc(sizeof(struct bootparamsent))))
		return (NULL);
	new->bp_name = NULL;
	new->*bp_bootparams = NULL;
	return (new);
}

struct bootparamsent	*manage_bootparamsent(int macro)
{
	static struct bootparamsent	*current;

	if (macro == NEW)
		current = new_bootparamsent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_bootparamsent: no decent macro\n", 38);
	return (NULL);
}
