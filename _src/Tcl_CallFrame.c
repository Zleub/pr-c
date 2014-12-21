#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_CallFrame	*new_Tcl_CallFrame(void)
{
	struct Tcl_CallFrame	*new;

	if (!(new = (struct Tcl_CallFrame*)malloc(sizeof(struct Tcl_CallFrame))))
		return (NULL);
	new->nsPtr = NULL;
	new->dummy1 = 0;
	new->dummy2 = 0;
	new->dummy3 = NULL;
	new->dummy4 = NULL;
	new->dummy5 = NULL;
	new->dummy6 = 0;
	new->dummy7 = NULL;
	new->dummy8 = NULL;
	new->dummy9 = 0;
	new->dummy10 = NULL;
	new->dummy11 = NULL;
	new->dummy12 = NULL;
	new->dummy13 = NULL;
	return (new);
}

struct Tcl_CallFrame	*manage_Tcl_CallFrame(int macro)
{
	static struct Tcl_CallFrame	*current;

	if (macro == NEW)
		current = new_Tcl_CallFrame();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_CallFrame: no decent macro\n", 38);
	return (NULL);
}
