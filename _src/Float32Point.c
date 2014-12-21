#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct Float32Point	*new_Float32Point(void)
{
	struct Float32Point	*new;

	if (!(new = (struct Float32Point*)malloc(sizeof(struct Float32Point))))
		return (NULL);
	new->x = 0;
	new->y = 0;
	return (new);
}

struct Float32Point	*manage_Float32Point(int macro)
{
	static struct Float32Point	*current;

	if (macro == NEW)
		current = new_Float32Point();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Float32Point: no decent macro\n", 37);
	return (NULL);
}
