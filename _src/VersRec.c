#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct VersRec	*new_VersRec(void)
{
	struct VersRec	*new;

	if (!(new = (struct VersRec*)malloc(sizeof(struct VersRec))))
		return (NULL);
	new->numericVersion = 0;
	new->countryCode = 0;
	new->shortVersion = 0;
	new->reserved = 0;
	return (new);
}

struct VersRec	*manage_VersRec(int macro)
{
	static struct VersRec	*current;

	if (macro == NEW)
		current = new_VersRec();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_VersRec: no decent macro\n", 32);
	return (NULL);
}
