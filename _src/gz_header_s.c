#include <stdlib.h>
#include <string.h>
#include <zlib.h>

enum e_macro
{
	NEW,
	GET
};

struct gz_header_s	*new_gz_header_s(void)
{
	struct gz_header_s	*new;

	if (!(new = (struct gz_header_s*)malloc(sizeof(struct gz_header_s))))
		return (NULL);
	new->text = 0;
	new->time = 0;
	new->xflags = 0;
	new->os = 0;
	new->extra = NULL;
	new->extra_len = 0;
	new->extra_max = 0;
	new->name = NULL;
	new->name_max = 0;
	new->comment = NULL;
	new->comm_max = 0;
	new->hcrc = 0;
	new->done = 0;
	return (new);
}

struct gz_header_s	*manage_gz_header_s(int macro)
{
	static struct gz_header_s	*current;

	if (macro == NEW)
		current = new_gz_header_s();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_gz_header_s: no decent macro\n", 36);
	return (NULL);
}
