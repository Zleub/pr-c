#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_ClassProcs	*new_Tk_ClassProcs(void)
{
	struct Tk_ClassProcs	*new;

	if (!(new = (struct Tk_ClassProcs*)malloc(sizeof(struct Tk_ClassProcs))))
		return (NULL);
	new->size = 0;
	new->worldChangedProc = NULL;
	new->createProc = NULL;
	new->modalProc = NULL;
	return (new);
}

struct Tk_ClassProcs	*manage_Tk_ClassProcs(int macro)
{
	static struct Tk_ClassProcs	*current;

	if (macro == NEW)
		current = new_Tk_ClassProcs();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_ClassProcs: no decent macro\n", 38);
	return (NULL);
}
