#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Parse	*new_Tcl_Parse(void)
{
	struct Tcl_Parse	*new;

	if (!(new = (struct Tcl_Parse*)malloc(sizeof(struct Tcl_Parse))))
		return (NULL);
	new->commentStart = NULL;
	new->commentSize = 0;
	new->commandStart = NULL;
	new->commandSize = 0;
	new->numWords = 0;
	new->tokenPtr = NULL;
	new->numTokens = 0;
	new->tokensAvailable = 0;
	new->errorType = 0;
	new->string = NULL;
	new->end = NULL;
	new->interp = NULL;
	new->term = NULL;
	new->incomplete = 0;
	bzero((void*)(&new->staticTokens), sizeof(Tcl_Token) * NUM_STATIC_TOKENS);
	new-> most commands = NULL;
	return (new);
}

struct Tcl_Parse	*manage_Tcl_Parse(int macro)
{
	static struct Tcl_Parse	*current;

	if (macro == NEW)
		current = new_Tcl_Parse();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Parse: no decent macro\n", 34);
	return (NULL);
}
