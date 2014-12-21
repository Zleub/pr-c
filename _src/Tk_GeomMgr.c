#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_GeomMgr	*new_Tk_GeomMgr(void)
{
	struct Tk_GeomMgr	*new;

	if (!(new = (struct Tk_GeomMgr*)malloc(sizeof(struct Tk_GeomMgr))))
		return (NULL);
	new->name = NULL;
	new->requestProc = NULL;
	new->lostSlaveProc = NULL;
	return (new);
}

struct Tk_GeomMgr	*manage_Tk_GeomMgr(int macro)
{
	static struct Tk_GeomMgr	*current;

	if (macro == NEW)
		current = new_Tk_GeomMgr();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_GeomMgr: no decent macro\n", 35);
	return (NULL);
}
