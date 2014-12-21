#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct TimeRecord	*new_TimeRecord(void)
{
	struct TimeRecord	*new;

	if (!(new = (struct TimeRecord*)malloc(sizeof(struct TimeRecord))))
		return (NULL);
	new->value = 0;
	new->scale = 0;
	new->base = 0;
	return (new);
}

struct TimeRecord	*manage_TimeRecord(int macro)
{
	static struct TimeRecord	*current;

	if (macro == NEW)
		current = new_TimeRecord();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_TimeRecord: no decent macro\n", 35);
	return (NULL);
}
