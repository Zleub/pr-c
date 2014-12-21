#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_SavedOptions	*new_Tk_SavedOptions(void)
{
	struct Tk_SavedOptions	*new;

	if (!(new = (struct Tk_SavedOptions*)malloc(sizeof(struct Tk_SavedOptions))))
		return (NULL);
	new->recordPtr = NULL;
	new->tkwin = 0;
	new->numItems = 0;
	bzero((void*)(&new->items), sizeof(Tk_SavedOption) * TK_NUM_SAVED_OPTIONS);
	new->nextPtr = NULL;
	new-> Points to next structure in list = NULL;
	return (new);
}

struct Tk_SavedOptions	*manage_Tk_SavedOptions(int macro)
{
	static struct Tk_SavedOptions	*current;

	if (macro == NEW)
		current = new_Tk_SavedOptions();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_SavedOptions: no decent macro\n", 40);
	return (NULL);
}
