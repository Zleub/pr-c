#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_CustomOption	*new_Tk_CustomOption(void)
{
	struct Tk_CustomOption	*new;

	if (!(new = (struct Tk_CustomOption*)malloc(sizeof(struct Tk_CustomOption))))
		return (NULL);
	new->parseProc = NULL;
	new->printProc = NULL;
	new->clientData = 0;
	return (new);
}

struct Tk_CustomOption	*manage_Tk_CustomOption(int macro)
{
	static struct Tk_CustomOption	*current;

	if (macro == NEW)
		current = new_Tk_CustomOption();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_CustomOption: no decent macro\n", 40);
	return (NULL);
}
