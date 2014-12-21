#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct FixedPoint	*new_FixedPoint(void)
{
	struct FixedPoint	*new;

	if (!(new = (struct FixedPoint*)malloc(sizeof(struct FixedPoint))))
		return (NULL);
	new->x = 0;
	new->y = 0;
	return (new);
}

struct FixedPoint	*manage_FixedPoint(int macro)
{
	static struct FixedPoint	*current;

	if (macro == NEW)
		current = new_FixedPoint();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_FixedPoint: no decent macro\n", 35);
	return (NULL);
}
