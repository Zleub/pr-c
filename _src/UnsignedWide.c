#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct UnsignedWide	*new_UnsignedWide(void)
{
	struct UnsignedWide	*new;

	if (!(new = (struct UnsignedWide*)malloc(sizeof(struct UnsignedWide))))
		return (NULL);
	new->hi = 0;
	new->lo = 0;
	return (new);
}

struct UnsignedWide	*manage_UnsignedWide(int macro)
{
	static struct UnsignedWide	*current;

	if (macro == NEW)
		current = new_UnsignedWide();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_UnsignedWide: no decent macro\n", 37);
	return (NULL);
}
