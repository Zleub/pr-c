#include <stdlib.h>
#include <string.h>
#include <tk.h>

enum e_macro
{
	NEW,
	GET
};

struct Tk_SmoothMethod	*new_Tk_SmoothMethod(void)
{
	struct Tk_SmoothMethod	*new;

	if (!(new = (struct Tk_SmoothMethod*)malloc(sizeof(struct Tk_SmoothMethod))))
		return (NULL);
	new->name = NULL;
	bzero((void*)(&new->xPoints[], double dblPoints), sizeof(XPoint) * ], double dblPoints[);
	new->numPoints, int numSteps)) = 0;
	return (new);
}

struct Tk_SmoothMethod	*manage_Tk_SmoothMethod(int macro)
{
	static struct Tk_SmoothMethod	*current;

	if (macro == NEW)
		current = new_Tk_SmoothMethod();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tk_SmoothMethod: no decent macro\n", 40);
	return (NULL);
}
