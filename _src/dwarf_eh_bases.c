#include <stdlib.h>
#include <string.h>
#include <unwind.h>

enum e_macro
{
	NEW,
	GET
};

struct dwarf_eh_bases	*new_dwarf_eh_bases(void)
{
	struct dwarf_eh_bases	*new;

	if (!(new = (struct dwarf_eh_bases*)malloc(sizeof(struct dwarf_eh_bases))))
		return (NULL);
	new->tbase = 0;
	new->dbase = 0;
	new->func = 0;
	return (new);
}

struct dwarf_eh_bases	*manage_dwarf_eh_bases(int macro)
{
	static struct dwarf_eh_bases	*current;

	if (macro == NEW)
		current = new_dwarf_eh_bases();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_dwarf_eh_bases: no decent macro\n", 39);
	return (NULL);
}
