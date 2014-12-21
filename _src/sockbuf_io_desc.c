#include <stdlib.h>
#include <string.h>
#include <lber.h>

enum e_macro
{
	NEW,
	GET
};

struct sockbuf_io_desc	*new_sockbuf_io_desc(void)
{
	struct sockbuf_io_desc	*new;

	if (!(new = (struct sockbuf_io_desc*)malloc(sizeof(struct sockbuf_io_desc))))
		return (NULL);
	new->sbiod_level = 0;
	new->sbiod_sb = NULL;
	new->sbiod_io = NULL;
	new->sbiod_pvt = NULL;
	new->sbiod_next = NULL;
	return (new);
}

struct sockbuf_io_desc	*manage_sockbuf_io_desc(int macro)
{
	static struct sockbuf_io_desc	*current;

	if (macro == NEW)
		current = new_sockbuf_io_desc();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_sockbuf_io_desc: no decent macro\n", 40);
	return (NULL);
}
