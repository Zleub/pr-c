#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_CanvasTextInfo	*new_Tk_CanvasTextInfo(void)
{
	struct Tk_CanvasTextInfo	*new;

	if (!(new = (struct Tk_CanvasTextInfo*)malloc(sizeof(struct Tk_CanvasTextInfo))))
		return (NULL);
	new->selBorder = 0;
	new->selBorderWidth = 0;
	new->selFgColorPtr = NULL;
	new->selItemPtr = NULL;
	new->selectFirst = 0;
	new->selectLast = 0;
	new->anchorItemPtr = NULL;
	new->selectAnchor = 0;
	new->insertBorder = 0;
	new->insertWidth = 0;
	new->insertBorderWidth = 0;
	new->focusItemPtr = NULL;
	new->gotFocus = 0;
	new->cursorOn = 0;
	return (new);
}

struct Tk_CanvasTextInfo	*manage_Tk_CanvasTextInfo(int macro)
{
	static struct Tk_CanvasTextInfo	*current;

	if (macro == NEW)
		current = new_Tk_CanvasTextInfo();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_CanvasTextInfo: no decent macro\n", 42);
	return (NULL);
}
