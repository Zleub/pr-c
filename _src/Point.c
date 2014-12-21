#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct Point	*new_Point(void)
{
	struct Point	*new;

	if (!(new = (struct Point*)malloc(sizeof(struct Point))))
		return (NULL);
	new->v = 0;
	new->h = 0;
	return (new);
}

struct Point	*manage_Point(int macro)
{
	static struct Point	*current;

	if (macro == NEW)
		current = new_Point();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Point: no decent macro\n", 30);
	return (NULL);
}
