#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_Item	*new_Tk_Item(void)
{
	struct Tk_Item	*new;

	if (!(new = (struct Tk_Item*)malloc(sizeof(struct Tk_Item))))
		return (NULL);
	new->id = 0;
	new->nextPtr = NULL;
	bzero((void*)(&new->staticTagSpace), sizeof(Tk_Uid) * TK_TAG_SPACE);
	new->tagPtr = NULL;
	new->tagSpace = 0;
	new->numTags = 0;
	new->typePtr = NULL;
	new->x1, y1, x2, y2 = 0;
	new->prevPtr = NULL;
	new->state = 0;
	new->reserved1 = NULL;
	new->redraw_flags = 0;
	new-> Starting here is additional type-specific stuff = NULL;
	return (new);
}

struct Tk_Item	*manage_Tk_Item(int macro)
{
	static struct Tk_Item	*current;

	if (macro == NEW)
		current = new_Tk_Item();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_Item: no decent macro\n", 32);
	return (NULL);
}
