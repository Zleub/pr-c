#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct NumVersion	*new_NumVersion(void)
{
	struct NumVersion	*new;

	if (!(new = (struct NumVersion*)malloc(sizeof(struct NumVersion))))
		return (NULL);
	new->majorRev = 0;
	new->minorAndBugRev = 0;
	new->stage = 0;
	new->nonRelRev = 0;
	return (new);
}

struct NumVersion	*manage_NumVersion(int macro)
{
	static struct NumVersion	*current;

	if (macro == NEW)
		current = new_NumVersion();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_NumVersion: no decent macro\n", 35);
	return (NULL);
}
