#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct Float80	*new_Float80(void)
{
	struct Float80	*new;

	if (!(new = (struct Float80*)malloc(sizeof(struct Float80))))
		return (NULL);
	new->exp = 0;
	bzero((void*)(&new->man), sizeof(UInt16) * 4);
	return (new);
}

struct Float80	*manage_Float80(int macro)
{
	static struct Float80	*current;

	if (macro == NEW)
		current = new_Float80();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Float80: no decent macro\n", 32);
	return (NULL);
}
