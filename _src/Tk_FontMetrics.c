#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_FontMetrics	*new_Tk_FontMetrics(void)
{
	struct Tk_FontMetrics	*new;

	if (!(new = (struct Tk_FontMetrics*)malloc(sizeof(struct Tk_FontMetrics))))
		return (NULL);
	new->ascent = 0;
	new->descent = 0;
	new->linespace = 0;
	return (new);
}

struct Tk_FontMetrics	*manage_Tk_FontMetrics(int macro)
{
	static struct Tk_FontMetrics	*current;

	if (macro == NEW)
		current = new_Tk_FontMetrics();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_FontMetrics: no decent macro\n", 39);
	return (NULL);
}
