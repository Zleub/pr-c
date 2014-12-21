#include <stdlib.h>
#include <string.h>
#include <MacTypes.h>

enum e_macro
{
	NEW,
	GET
};

struct ProcessSerialNumber	*new_ProcessSerialNumber(void)
{
	struct ProcessSerialNumber	*new;

	if (!(new = (struct ProcessSerialNumber*)malloc(sizeof(struct ProcessSerialNumber))))
		return (NULL);
	new->highLongOfPSN = 0;
	new->lowLongOfPSN = 0;
	return (new);
}

struct ProcessSerialNumber	*manage_ProcessSerialNumber(int macro)
{
	static struct ProcessSerialNumber	*current;

	if (macro == NEW)
		current = new_ProcessSerialNumber();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ProcessSerialNumber: no decent macro\n", 44);
	return (NULL);
}
