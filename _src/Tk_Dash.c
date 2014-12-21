#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_Dash	*new_Tk_Dash(void)
{
	struct Tk_Dash	*new;

	if (!(new = (struct Tk_Dash*)malloc(sizeof(struct Tk_Dash))))
		return (NULL);
	new->number = 0;
	new->pt = NULL;
