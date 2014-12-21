#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_FakeWin	*new_Tk_FakeWin(void)
{
	struct Tk_FakeWin	*new;

	if (!(new = (struct Tk_FakeWin*)malloc(sizeof(struct Tk_FakeWin))))
		return (NULL);
	new->display = NULL;
	new->dummy1 = NULL;
	new->screenNum = 0;
	new->visual = NULL;
	new->depth = 0;
	new->window = 0;
	new->dummy2 = NULL;
	new->dummy3 = NULL;
	new->parentPtr = 0;
	new->dummy4 = NULL;
	new->dummy5 = NULL;
	new->pathName = NULL;
	new->nameUid = 0;
	new->classUid = 0;
	new->changes = 0;
	new->dummy6 = 0;
	new->atts = 0;
	new->dummy7 = 0;
	new->flags = 0;
	new->dummy8 = NULL;
	new->dummy9 = 0;
	new->dummy10 = NULL;
	new->dummy11 = 0;
	new->dummy12 = 0;
	new->dummy13 = NULL;
	new->dummy14 = NULL;
	new->dummy15 = 0;
	new->reqWidth, reqHeight = 0;
	new->internalBorderLeft = 0;
	new->dummy16 = NULL;
	new->dummy17 = NULL;
	new->dummy18 = 0;
	new->dummy19 = NULL;
	new->internalBorderRight = 0;
	new->internalBorderTop = 0;
	new->internalBorderBottom = 0;
	new->minReqWidth = 0;
	new->minReqHeight = 0;
	return (new);
}

struct Tk_FakeWin	*manage_Tk_FakeWin(int macro)
{
	static struct Tk_FakeWin	*current;

	if (macro == NEW)
		current = new_Tk_FakeWin();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_FakeWin: no decent macro\n", 35);
	return (NULL);
}
