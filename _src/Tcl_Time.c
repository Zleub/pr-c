#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Time	*new_Tcl_Time(void)
{
	struct Tcl_Time	*new;

	if (!(new = (struct Tcl_Time*)malloc(sizeof(struct Tcl_Time))))
		return (NULL);
	new->sec = 0;
	new->usec = 0;
	return (new);
}

struct Tcl_Time	*manage_Tcl_Time(int macro)
{
	static struct Tcl_Time	*current;

	if (macro == NEW)
		current = new_Tcl_Time();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Time: no decent macro\n", 33);
	return (NULL);
}
