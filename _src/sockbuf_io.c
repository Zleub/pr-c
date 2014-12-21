#include <stdlib.h>
#include <string.h>
#include <lber.h>

enum e_macro
{
	NEW,
	GET
};

struct sockbuf_io	*new_sockbuf_io(void)
{
	struct sockbuf_io	*new;

	if (!(new = (struct sockbuf_io*)malloc(sizeof(struct sockbuf_io))))
		return (NULL);
	new->sbi_setup = NULL;
	new->sbi_remove = NULL;
	new->sbi_ctrl = NULL;
	new->) = 0;
	new->) = 0;
	new->sbi_close = NULL;
	return (new);
}

struct sockbuf_io	*manage_sockbuf_io(int macro)
{
	static struct sockbuf_io	*current;

	if (macro == NEW)
		current = new_sockbuf_io();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sockbuf_io: no decent macro\n", 35);
	return (NULL);
}
