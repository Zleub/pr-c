#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct Float96	*new_Float96(void)
{
	struct Float96	*new;

	if (!(new = (struct Float96*)malloc(sizeof(struct Float96))))
		return (NULL);
	bzero((void*)(&new->exp), sizeof(SInt16) * 2);
	bzero((void*)(&new->man), sizeof(UInt16) * 4);
	return (new);
}

struct Float96	*manage_Float96(int macro)
{
	static struct Float96	*current;

	if (macro == NEW)
		current = new_Float96();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Float96: no decent macro\n", 32);
	return (NULL);
}
