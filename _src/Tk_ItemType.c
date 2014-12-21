#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_ItemType	*new_Tk_ItemType(void)
{
	struct Tk_ItemType	*new;

	if (!(new = (struct Tk_ItemType*)malloc(sizeof(struct Tk_ItemType))))
		return (NULL);
	new->name = NULL;
	new->itemSize = 0;
	new->createProc = NULL;
	new->configSpecs = NULL;
	new->configProc = NULL;
	new->coordProc = NULL;
	new->deleteProc = NULL;
	new->displayProc = NULL;
	new->alwaysRedraw = 0;
	new->pointProc = NULL;
	new->areaProc = NULL;
	new->postscriptProc = NULL;
	new->scaleProc = NULL;
	new->translateProc = NULL;
	new->indexProc = NULL;
	new->icursorProc = NULL;
	new->selectionProc = NULL;
	new->insertProc = NULL;
	new->dCharsProc = NULL;
	new->nextPtr = NULL;
	new->reserved1 = NULL;
	new->reserved2 = 0;
	new->reserved3 = NULL;
	new->reserved4 = NULL;
	return (new);
}

struct Tk_ItemType	*manage_Tk_ItemType(int macro)
{
	static struct Tk_ItemType	*current;

	if (macro == NEW)
		current = new_Tk_ItemType();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_ItemType: no decent macro\n", 36);
	return (NULL);
}
